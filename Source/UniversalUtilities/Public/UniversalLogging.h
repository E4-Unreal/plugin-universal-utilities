#pragma once

DECLARE_LOG_CATEGORY_EXTERN(LogUniversalUtilities, Log, All)

#define CATEGORY LogUniversalUtilities

// 클래스::메서드(줄 위치)
#define CALL_INFO (FString(__FUNCTION__) + TEXT("(") + FString::FromInt(__LINE__) + TEXT(")"))

// 액터 이름(Server or Client) - 액터에서 호출
#define ACTOR_INFO (GetName() + TEXT("(") + (HasAuthority() ? FString("Server") : FString("Client")) + TEXT(")"))

// 액터 이름(Server or Client) - 액터 컴포넌트에서 호출
#define ACTOR_COMPONENT_INFO (GetOwner()->GetName() + TEXT("(") + (GetOwner()->HasAuthority() ? FString("Server") : FString("Client")) + TEXT(")"))

// 일반 로그
#define LOG(Verbosity, Format, ...) UE_LOG(CATEGORY, Verbosity, TEXT("%s > %s > %s"), *GetName(), *CALL_INFO, *FString::Printf(Format, ##__VA_ARGS__))

// Server or Client > 오브젝트 > 클래스::메서드(줄 위치) > 코멘트
#define LOG_ACTOR(Verbosity, Format, ...) UE_LOG(CATEGORY, Verbosity, TEXT("%s > %s > %s"), *ACTOR_INFO, *CALL_INFO, *FString::Printf(Format, ##__VA_ARGS__))

// Server or Client > 오브젝트 > 클래스::메서드(줄 위치) > 코멘트
#define LOG_ACTOR_COMPONENT(Verbosity, Format, ...) UE_LOG(CATEGORY, Verbosity, TEXT("%s > %s > %s"), *ACTOR_COMPONENT_INFO, *CALL_INFO, *FString::Printf(Format, ##__VA_ARGS__))

// Crash 없이 Assertion 로그 출력
#define LOG_CHECK(Expr, ...) {if(Expr) {LOG_CALLINFO_COMMENT(CATEGORY, Error, TEXT("ASSERTION : %s"), TEXT("'"#Expr"'"));}}

// 구현 예정인 기능이 호출된 경우 로그 출력
#define LOG_TODO LOG(Warning, TEXT("Need to be implemented"))

// 인터페이스 기본 구현이 호출된 경우 로그 출력
#define LOG_TODO_INTERFACE UE_LOG(CATEGORY, Warning, TEXT("%s > Need to be implemented"), *CALL_INFO)

// 특정 변수가 null일 경우 로그 출력
#define LOG_CHECK_NULL(Variable) if(Variable == nullptr) LOG(Error, TEXT("%s is NULL"), *FString(#Variable))
