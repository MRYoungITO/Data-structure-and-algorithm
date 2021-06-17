#pragma once
#include <string>

using namespace std;

#define ODU_TYPE_331_FLAG "331"
#define ODU_TYPE_335_FLAG "335"

enum class ODU_TYPE
{
	OUD_TYPE_331,
	ODU_TYPE_335,
	ODU_TYPE_UNKNOWN
};

// ODU类, 用于处理老型号ODU331设备
class ODU
{
public:
	ODU();
	virtual int getTxFre();  //获取发射频率
	virtual bool setTxFre(int);  //设置发射频率

	virtual int getRxFre();  //获取接收频率
	virtual bool setRxFre(int);  //设置接收频率

	virtual float getTxPower();  //获取发射功率
	virtual bool setTxPower(float);  //设置发射功率

	virtual float getRxL();  //获取接收电平

	virtual bool heartBeat();  //心跳包

	virtual string name();  //获取该设备的名称

	ODU_TYPE getODUType();  // 获取当前ODU类型
protected:
	int txFre;  //发射频率
	int rxFre;	//接收频率
	float txPower;  //发射功率
	float rxL;	//接收电平

	ODU_TYPE type;
};

