#include <iostream>
#include <ctime>

int main( )
{
   // 获取基于当前系统的当前日期/时间
   time_t now = time(0);

   // 把 now 转换为字符串形式
   char* dt = ctime(&now);

   std::cout << "本地日期和时间：" << dt << std::endl;

   // 把 now 转换为 tm 结构
   tm *gmtm = gmtime(&now);
   dt = asctime(gmtm);

   std::cout << "UTC 日期和时间："<< dt << std::endl;

   return 0;
}