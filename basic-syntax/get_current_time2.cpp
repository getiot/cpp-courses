#include <iostream>
#include <ctime>

int main(void)
{
   // 获取基于当前系统的当前日期 / 时间
   time_t now = time(0);

   std::cout << "Number of sec since January 1,1970:";
   std::cout << now;
   std::cout << std::endl;

   tm *ltm = localtime(&now);

   // 输出 tm 结构的各个组成部分

   std::cout << "Year: "<< 1900 + ltm->tm_year << std::endl;
   std::cout << "Month: "<< 1 + ltm->tm_mon<< std::endl;
   std::cout << "Day: "<<  ltm->tm_mday << std::endl;
   std::cout << "Time: "<< 1 + ltm->tm_hour << ":";
   std::cout << 1 + ltm->tm_min << ":";
   std::cout << 1 + ltm->tm_sec << std::endl;

   return 0;
}