#pragma once

EXTERN_C_START

NTSTATUS GetPspSetCreateProcessNotifyRoutine(DWORD64 *Address);

NTSTATUS GetProcessorCallbackAddress(_In_ WDFREQUEST Request,
	_In_ size_t InputBufferLength,
	_In_ size_t OutputBufferLength,
	_Out_opt_ size_t* Resquestlength);

//��ȡPspCreateProcessNotifyRoutineCount  
NTSTATUS GetPspCreateProcessNotifyRoutine(
	_In_ DWORD64 PspSetCreateProcessNotifyRoutine_Addr,
	_Out_ DWORD64 *Address);

//��ȡPspCreateProcessNotifyRoutine  
NTSTATUS GetPspCreateProcessNotifyRoutineCount(
	_In_ DWORD64 PspSetCreateProcessNotifyRoutine_Addr,
	_Out_ DWORD64 *RoutineCount);

NTSTATUS GetPspSetCreateThreadNotifyRoutine(DWORD64 *Address);

NTSTATUS GetThreadCallbackAddress(_In_ WDFREQUEST Request,
	_In_ size_t InputBufferLength,
	_In_ size_t OutputBufferLength,
	_Out_opt_ size_t* Resquestlength);

//��ȡPspCreateThreadNotifyRoutineCount  
NTSTATUS GetPspCreateThreadNotifyRoutine(
	_In_ DWORD64 PspSetCreateThreadNotifyRoutine_Addr,
	_Out_ DWORD64 *Address);

//��ȡPspCreateThreadNotifyRoutine  
NTSTATUS GetPspCreateThreadNotifyRoutineCount(
	_In_ DWORD64 PspSetCreateThreadNotifyRoutine_Addr,
	_Out_ DWORD64 *RoutineCount);

NTSTATUS GetPsSetLoadImageNotifyRoutineEx(DWORD64 *Address);

NTSTATUS GetLoadImageCallbackAddress(_In_ WDFREQUEST Request,
	_In_ size_t InputBufferLength,
	_In_ size_t OutputBufferLength,
	_Out_opt_ size_t* Resquestlength);

//��ȡPspCreateLoadImageNotifyRoutineCount  
NTSTATUS GetPspCreateLoadImageNotifyRoutine(
	_In_ DWORD64 PspSetCreateLoadImageNotifyRoutine_Addr,
	_Out_ DWORD64 *Address);

//��ȡPspCreateLoadImageNotifyRoutine  
NTSTATUS GetPspCreateLoadImageNotifyRoutineCount(
	_In_ DWORD64 PspSetCreateLoadImageNotifyRoutine_Addr,
	_Out_ DWORD64 *RoutineCount);

NTSTATUS GetCmpInsertCallbackInListByAltitude(DWORD64 *Address);

NTSTATUS GetCmpRegisterCallbackAddress(_In_ WDFREQUEST Request,
	_In_ size_t InputBufferLength,
	_In_ size_t OutputBufferLength,
	_Out_opt_ size_t* Resquestlength);

//��ȡPspCreateCmpRegisterNotifyRoutineCount  
NTSTATUS GetCallbackListHead(
	_In_ DWORD64 CmpInsertCallbackInListByAltitude_Addr,
	_Out_ DWORD64 *Address);

//��ȡPspCreateCmpRegisterNotifyRoutine  
NTSTATUS GetCmpCallBackCount(
	_In_ DWORD64 CmpInsertCallbackInListByAltitude_Addr,
	_Out_ DWORD64 *RoutineCount);

NTSTATUS GetKeBugCheckCallbackAddress(_In_ WDFREQUEST Request,
	_In_ size_t InputBufferLength,
	_In_ size_t OutputBufferLength,
	_Out_opt_ size_t* Resquestlength);

//��ȡGetKeBugCheckCallbackListHead
NTSTATUS GetKeBugCheckCallbackListHead(
	_Out_ DWORD64 *Address);

NTSTATUS GetKeRegisterBugCheckReasonCallbackAddress(_In_ WDFREQUEST Request,
	_In_ size_t InputBufferLength,
	_In_ size_t OutputBufferLength,
	_Out_opt_ size_t* Resquestlength);

//��ȡGetKeRegisterBugCheckReasonCallbackListHead
NTSTATUS GetKeRegisterBugCheckReasonCallbackListHead(
	_Out_ DWORD64 *Address);

NTSTATUS GetIoRegisterShutdownNotificationAddress(_In_ WDFREQUEST Request,
	_In_ size_t InputBufferLength,
	_In_ size_t OutputBufferLength,
	_Out_opt_ size_t* Resquestlength);

NTSTATUS GetIopNotifyShutdownQueueHead(
		_Out_ DWORD64 *Address);

NTSTATUS GetIoRegisterLastChanceShutdownNotificationAddress(_In_ WDFREQUEST Request,
	_In_ size_t InputBufferLength,
	_In_ size_t OutputBufferLength,
	_Out_opt_ size_t* Resquestlength);

NTSTATUS GetIopNotifyLastChanceShutdownQueueHead(
	_Out_ DWORD64 *Address);

NTSTATUS GetIoRegisterFsRegistrationChangeAddress(_In_ WDFREQUEST Request,
	_In_ size_t InputBufferLength,
	_In_ size_t OutputBufferLength,
	_Out_opt_ size_t* Resquestlength);
NTSTATUS GetIoRegisterFsRegistrationChange(
	_Out_ DWORD64 *Address);
NTSTATUS GetIopFileSystemQueueHead(
	_In_ DWORD64 IoRegisterFsRegistrationChange_Addr,
	_Out_ DWORD64 *IopFileSystemQueueHead_Addr);

NTSTATUS GetIoRegisterPlugPlayNotificationAddress(_In_ WDFREQUEST Request,
	_In_ size_t InputBufferLength,
	_In_ size_t OutputBufferLength,
	_Out_opt_ size_t* Resquestlength);
NTSTATUS GetIoRegisterPnpDeviceClassNotifyList(
	_Out_ DWORD64 *Address);

NTSTATUS GetPoRegisterPowerSettingCallbackAddress(_In_ WDFREQUEST Request,
	_In_ size_t InputBufferLength,
	_In_ size_t OutputBufferLength,
	_Out_opt_ size_t* Resquestlength);

NTSTATUS GetPopRegisteredPowerSettingCallbacksList(
	_Out_ DWORD64 *Address);
EXTERN_C_END