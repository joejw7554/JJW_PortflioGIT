#include "CPlayer.h"

#include "InputAction.h"
#include "InputMappingContext.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "Engine/LocalPlayer.h"

#include "Camera/CameraComponent.h"
#include "GameFrameWork/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"

ACPlayer::ACPlayer()
{
	PrimaryActorTick.bCanEverTick = true;

	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>("SpringArm");
	SpringArmComp->SetupAttachment(RootComponent);
	SpringArmComp->TargetArmLength = 300.f;

	CameraComp = CreateDefaultSubobject<UCameraComponent>("FollowCamera");
	CameraComp->SetupAttachment(SpringArmComp);


	//회전부분
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	SpringArmComp->bUsePawnControlRotation = true;
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->MaxWalkSpeed = WalkSpeed;

}

void ACPlayer::BeginPlay()
{
	Super::BeginPlay();

	if (APlayerController* PlayerController = Cast<APlayerController>(GetController()))
	{
		if (UEnhancedInputLocalPlayerSubsystem* subSystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			subSystem->AddMappingContext(PlayerMappingContext, 0);
		}
	}

}

void ACPlayer::Move(const FInputActionValue& Value)
{
	const FVector2D VectorParam = Value.Get<FVector2D>();

	FRotator YawRotation = FRotator(0, GetControlRotation().Yaw, 0);

	FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	AddMovementInput(ForwardDirection, VectorParam.Y);
	AddMovementInput(RightDirection, VectorParam.X);
}

void ACPlayer::Look(const FInputActionValue& Value)
{
	const FVector2D VectorParam = Value.Get<FVector2D>();


	AddControllerYawInput(VectorParam.X);
	AddControllerPitchInput(VectorParam.Y);
}

void ACPlayer::Sprint(const FInputActionValue& Value)
{
	bool ActionValue = Value.Get<bool>();

	if (ActionValue)
	{
		GetCharacterMovement()->MaxWalkSpeed = SprintSpeed;
	}
	else
	{
		GetCharacterMovement()->MaxWalkSpeed = WalkSpeed;
	}
}

void ACPlayer::Jump(const FInputActionValue& Value)
{
	bool ActionValue = Value.Get<bool>(); //왜 점프가 안되지?

	if (ActionValue)
	{
		UE_LOG(LogTemp, Log, L"Called");
		ACharacter::Jump();
	}
}


void ACPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ACPlayer::Move);
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &ACPlayer::Look);
		EnhancedInputComponent->BindAction(SprintAction, ETriggerEvent::Triggered, this, &ACPlayer::Sprint);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Triggered, this, &ACPlayer::Jump);
	}


}

