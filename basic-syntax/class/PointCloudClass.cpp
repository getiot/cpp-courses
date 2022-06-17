#include <iostream>
#include <boost/endian/arithmetic.hpp>
#include <memory>

//----------------------------------------------------------------------------
//! @brief Simple getter that handles conversion to native unsigned integer types.
#define GET_NATIVE_UINT(n, attr) uint ## n ##_t Get ## attr() const { return this->attr; }
#define SET_NATIVE_UINT(n, attr) void Set ## attr(uint ## n ##_t x) { this->attr = x; }

#define BIT(n)                  ( 1<<(n) )
//! Create a bitmask of length \a len.
#define BIT_MASK(len)           ( BIT(len)-1 )

//! Create a bitfield mask of length \a starting at bit \a start.
#define BF_MASK(start, len)     ( BIT_MASK(len)<<(start) )

//! Extract a bitfield of length \a len starting at bit \a start from \a y.
#define BF_GET(y, start, len)   ( ((y)>>(static_cast<decltype(y)>(start))) & BIT_MASK(len) )

//! Prepare a bitmask for insertion or combining.
#define BF_PREP(x, start, len)  ( ((x)&BIT_MASK(len)) << (start) )

//! Insert a new bitfield value x into y.
#define BF_SET(y, x, start, len)    ( y= ((y) &~ BF_MASK(start, len)) | BF_PREP(x, start, len) )

#define PANDAR128_LASER_NUM (128)
#define PANDAR128_BLOCK_NUM (2)
//#define MAX_BLOCK_NUM (8)

#define LASER_NUM                 (8)         /* 默认 25 */
#define MAX_POINT_NUM_IN_BLOCK    LASER_NUM
#define MAX_BLOCK_NUM             (4)
#define ROLL_NUM                  (3)         /* 配置的回波次数，最大3回波 */


#pragma pack(push, 1)
//! @brief class representing the raw measure
/*
   0               1               2               3
   0 1 2 3 4 5 6 7 0 1 2 3 4 5 6 7 0 1 2 3 4 5 6 7 0 1 2 3 4 5 6 7
  +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
  |           Distance         |            Intensity             |
  +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
 */
class Pandar128Unit
{
private :
  // Distance
  boost::endian::little_uint16_t Distance;

  // Intensity
  boost::endian::little_uint8_t Intensity;

public :
  GET_NATIVE_UINT(16, Distance)
  SET_NATIVE_UINT(16, Distance)
  GET_NATIVE_UINT(8, Intensity)
  SET_NATIVE_UINT(8, Intensity)
};
#pragma pack(pop)

#pragma pack(push, 1)
class Pandar128Block
{
private :

  // Azimuth
  boost::endian::little_uint16_t Azimuth;

public :
  Pandar128Unit units[PANDAR128_LASER_NUM];

public :
  GET_NATIVE_UINT(16, Azimuth)
  SET_NATIVE_UINT(16, Azimuth)
};
#pragma pack(pop)


/* Custom */
#pragma pack(push, 1)
class AsensingUnit
{
private :
  boost::endian::little_uint16_t Distance;  /* 球坐标系径向距离 radius（单位 mm） */
  boost::endian::little_uint16_t Azimuth;   /* 球坐标系水平夹角，方位角（分辨率 0.01°） */
  boost::endian::little_uint16_t Elevation; /* 球坐标系垂直夹角，俯仰角/极角（分辨率 0.01°） */
  boost::endian::little_uint8_t  Intensity; /* 反射强度 intensity */
  boost::endian::little_uint16_t Reserved;  /* 保留 */

public :
  GET_NATIVE_UINT(16, Distance)
  SET_NATIVE_UINT(16, Distance)
  GET_NATIVE_UINT(16, Azimuth)
  SET_NATIVE_UINT(16, Azimuth)
  GET_NATIVE_UINT(16, Elevation)
  SET_NATIVE_UINT(16, Elevation)
  GET_NATIVE_UINT(8,  Intensity)
  SET_NATIVE_UINT(8,  Intensity)
  GET_NATIVE_UINT(16, Reserved)
  SET_NATIVE_UINT(16, Reserved)
};
#pragma pack(pop)

#pragma pack(push, 1)
class AsensingBlock
{
private :
  boost::endian::little_uint8_t channelNum;
  boost::endian::little_uint8_t timeOffSet;
  boost::endian::little_uint8_t returnSn;
  boost::endian::little_uint8_t reserved;

public :
  AsensingUnit units[MAX_POINT_NUM_IN_BLOCK];

public :
  GET_NATIVE_UINT(8, channelNum)
  SET_NATIVE_UINT(8, channelNum)
  GET_NATIVE_UINT(8, timeOffSet)
  SET_NATIVE_UINT(8, timeOffSet)
  GET_NATIVE_UINT(8, returnSn)
  SET_NATIVE_UINT(8, returnSn)
  GET_NATIVE_UINT(8, reserved)
  SET_NATIVE_UINT(8, reserved)
};
#pragma pack(pop)


#pragma pack(push, 1)
//! @brief class representing the Raw packet
/*
   0               1               2               3
   0 1 2 3 4 5 6 7 0 1 2 3 4 5 6 7 0 1 2 3 4 5 6 7 0 1 2 3 4 5 6 7
  +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
  |               Sob              |  VersionMajor | VersionMinor |
  +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
  |    DistUnit    |     Flags     |   LaserNum    |  BlockNum    |
  +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
  |    EchoCount   |   EchoNum     |          Reserved            |
  +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
 */
class AsensingHeader
{
private:
  boost::endian::little_uint32_t Sob;
  boost::endian::little_uint32_t FrameID;
  boost::endian::little_uint16_t SeqNum;
  boost::endian::little_uint16_t PkgLen;
  boost::endian::little_uint16_t LidarType;
  boost::endian::little_uint8_t  VersionMajor;  /* Protocol version */
  boost::endian::little_uint8_t  VersionMinor;

  boost::endian::little_uint8_t  UTCTime0;      /* Year   */
  boost::endian::little_uint8_t  UTCTime1;      /* Month  */
  boost::endian::little_uint8_t  UTCTime2;      /* Mday   */
  boost::endian::little_uint8_t  UTCTime3;      /* Hour   */
  boost::endian::little_uint8_t  UTCTime4;      /* Minute */
  boost::endian::little_uint8_t  UTCTime5;      /* Second */

  boost::endian::little_uint32_t Timestamp;     /* Microseconds */

  boost::endian::little_uint8_t  MeasureMode;
  boost::endian::little_uint8_t  LaserNum;
  boost::endian::little_uint8_t  BlockNum;
  boost::endian::little_uint8_t  EchoCount;     /* Wave mode: 第一回波、最后回波、最强回波、双回波 */
  boost::endian::little_uint8_t  TimeSyncMode;  /* 1: System time, 2: 1PPS, 3: PTP */
  boost::endian::little_uint8_t  TimeSyncStat;
  boost::endian::little_uint8_t  MemsTemp;      /* Temperature of MEMS */
  boost::endian::little_uint8_t  SlotNum;

  boost::endian::little_uint16_t Reserved1;     /* e.g DistUnit, Flags ... */
  boost::endian::little_uint16_t Reserved2;
  boost::endian::little_uint16_t Reserved3;

public:
  GET_NATIVE_UINT(32, Sob)
  SET_NATIVE_UINT(32, Sob)
  GET_NATIVE_UINT(32, FrameID)
  SET_NATIVE_UINT(32, FrameID)
  GET_NATIVE_UINT(16, SeqNum)
  SET_NATIVE_UINT(16, SeqNum)
  GET_NATIVE_UINT(16, PkgLen)
  SET_NATIVE_UINT(16, PkgLen)
  GET_NATIVE_UINT(16, LidarType)
  SET_NATIVE_UINT(16, LidarType)
  GET_NATIVE_UINT(8, VersionMajor)
  SET_NATIVE_UINT(8, VersionMajor)
  GET_NATIVE_UINT(8, VersionMinor)
  SET_NATIVE_UINT(8, VersionMinor)

  GET_NATIVE_UINT(32, Timestamp)
  SET_NATIVE_UINT(32, Timestamp)

  GET_NATIVE_UINT(8, UTCTime0)
  SET_NATIVE_UINT(8, UTCTime0)
  GET_NATIVE_UINT(8, UTCTime1)
  SET_NATIVE_UINT(8, UTCTime1)
  GET_NATIVE_UINT(8, UTCTime2)
  SET_NATIVE_UINT(8, UTCTime2)
  GET_NATIVE_UINT(8, UTCTime3)
  SET_NATIVE_UINT(8, UTCTime3)
  GET_NATIVE_UINT(8, UTCTime4)
  SET_NATIVE_UINT(8, UTCTime4)
  GET_NATIVE_UINT(8, UTCTime5)
  SET_NATIVE_UINT(8, UTCTime5)
  
  GET_NATIVE_UINT(8, MeasureMode)
  SET_NATIVE_UINT(8, MeasureMode)
  GET_NATIVE_UINT(8, LaserNum)
  SET_NATIVE_UINT(8, LaserNum)
  GET_NATIVE_UINT(8, BlockNum)
  SET_NATIVE_UINT(8, BlockNum)
  GET_NATIVE_UINT(8, EchoCount)
  SET_NATIVE_UINT(8, EchoCount)
  GET_NATIVE_UINT(8, TimeSyncMode)
  SET_NATIVE_UINT(8, TimeSyncMode)
  GET_NATIVE_UINT(8, TimeSyncStat)
  SET_NATIVE_UINT(8, TimeSyncStat)
  GET_NATIVE_UINT(8, MemsTemp)
  SET_NATIVE_UINT(8, MemsTemp)
  GET_NATIVE_UINT(8, SlotNum)
  SET_NATIVE_UINT(8, SlotNum)

  GET_NATIVE_UINT(16, Reserved1)
  SET_NATIVE_UINT(16, Reserved1)
  GET_NATIVE_UINT(16, Reserved2)
  SET_NATIVE_UINT(16, Reserved2)
  GET_NATIVE_UINT(16, Reserved3)
  SET_NATIVE_UINT(16, Reserved3)
};
#pragma pack(pop)

#pragma pack(push, 1)
class AsensingTail
{
private:
  boost::endian::little_uint8_t Reserved11;
  boost::endian::little_uint8_t Reserved12;
  boost::endian::little_uint8_t Reserved13;

  boost::endian::little_uint8_t Reserved21;
  boost::endian::little_uint8_t Reserved22;
  boost::endian::little_uint8_t Reserved23;

  boost::endian::little_uint16_t Padding1;  //+
  boost::endian::little_uint16_t Padding2;  //+
  boost::endian::little_uint8_t Padding3;   //+

  boost::endian::little_uint8_t ShutdownFlag;

  //boost::endian::little_uint8_t Reserved3[3];

  boost::endian::little_uint8_t ReturnMode;

  boost::endian::little_uint16_t MotorSpeed;

 // boost::endian::little_uint8_t FactoryInfo;

  boost::endian::little_uint32_t SeqNum;

public:
  GET_NATIVE_UINT(8,  ShutdownFlag)
  SET_NATIVE_UINT(8,  ShutdownFlag)
  GET_NATIVE_UINT(16, MotorSpeed)
  SET_NATIVE_UINT(16, MotorSpeed)
  GET_NATIVE_UINT(8,  ReturnMode)
  SET_NATIVE_UINT(8,  ReturnMode)
  GET_NATIVE_UINT(32, SeqNum)
  SET_NATIVE_UINT(32, SeqNum)
};
#pragma pack(pop)

#pragma pack(push, 1)
//! @brief class representing the Hesai Packet
struct AsensingPacket{
  AsensingHeader header;

  Pandar128Block blocks[PANDAR128_BLOCK_NUM];

  // PANDAR128_CRC_SIZE is equal to 4
  boost::endian::little_uint32_t crc;

  // PANDAR128_FUNCTION_SAFETY_SIZE is equal to 17
  boost::endian::little_uint8_t functionSafety[17];

  AsensingTail tail;
};
#pragma pack(pop)


int main(void)
{
    AsensingPacket packet;
    std::cout << "Size of AsensingPacket = " << sizeof(packet) << std::endl;
    std::cout << "Size of AsensingPacket.Header = " << sizeof(packet.header) << std::endl;
    std::cout << "Size of AsensingPacket.Block  = " << sizeof(packet.blocks) << std::endl;
    std::cout << "Size of AsensingPacket.Tail   = " << sizeof(packet.tail) << std::endl;

    return 0;
}
