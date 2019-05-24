#pragma once
class AC_server { //http server
private:
	
	AdminController *A_controller;
	ClientController *C_controller;
	FronterController *F_controller;
	ManageController *M_controller;
public:
	AC_server();
	listen(request, response);
};


class AdminController {
private:
	int RoomNum;
	Room *RoomState;
	AdminServiceObj AS_obj;	
public:
	void PowerOn(ClientController *C_controller);
	bool setPara(int Mode,float Temp_highLimit,float Temp_lowLimit,float default_TargetTemp,float FeeRate_H,float FeeRate_M,float FeeRate_L）;
	bool StartUp(ClientController *C_controller);
	void CheckRoomState(int list_Room[]);
};
class AdminServiceObj {

public:	
	bool Initial(int Mode,float Temp_highLimit,float Temp_lowLimit,float default_TargetTemp,float FeeRate_H,float FeeRate_M,float FeeRate_L）;
	Room* CheckRoomState(int list_Room[]);
};

class ClientController { //调度对象
private:
	Wait_Queue *wq;
	Service_Queue *sq;
	int MaxServiceNum;
	int ServingNum;
	int Ready;
public:
	ClientController();
	bool RequestOn(int RoomID, float CurrentRoomTemp);
	bool ChangeTargetTemp(int RoomId,float TargetTemp,float CurrentTemp,int Speed); 
	bool ChangeSpeed(int RoomId,float TargetTemp,float CurrentTemp,int Speed);
	bool RequestOff(int RoomID);
	bool JudgePriority(int RoomID,int Speed); 
	void SwitchService();//slot
};

class Wait_Queue {
private:
	Wait_Unit *WaitHeader;
	int TimeToWait;
public:
	Wait_Queue();
	bool Add(int RoomID,,float TargetTemp,float CurrentTemp,int Speed);
	bool ChangeTargetTemp(int RoomID, float TargetTemp);
	void Remove(int RoomID);
};

class Wait_Unit {
private:
	int RoomID;
	float TargetTemp;
	float CurrentTemp;
	float Speed;
	int WaitTime;
};

class Service_Unit {
	int RoomID;
	int ServiceID;
	float Speed;
	int ServiceTime;
};
class Service_Queue {
private:
	Service_Unit *S_Header;
public:
	Service_Queue();
	bool Add(int RoomID, int Service_ID, float Speed);
	int Is_In(Room_ID);
	bool Remove(RoomID);
	
};

class ClientServiceObj {
private:
	int ServiceId;
	int RoomId;
	Room R;
public:
	float GetFee();
	float GetFeeRate();
	void AdjustTemp(); //timer
};

class Room {
private:
	float CurrentTemp;
	int RoomID;
	float Fee;
	float FeeRate;
	int Mode;
	float TargetTemp;
	float FanSpeed;
public:
	bool GetRoomMes(int RoomId);//从数据库中获取房间信息
};

class FronterController{
	CreateRDR(RoomId,date_in,date_out)
	PrintRDR(RoomId,list_RDR)
	CreateInvoice(RoomId,date_in,date_out)
	PrintInvoice(RoomId,date_in,date_out,Total_Fee)
};
class FronterServiceObj{
	
};
class DetailRecord{
	
};
class Invoice{
	
};
class ManagerController{
	public:
		QueryReport(list_RoomId,type_Report,date);
		PrintReport(ReportId,date)
};
class ManagerServiceObj{
	
};
class Report{
	
};
