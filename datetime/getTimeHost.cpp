#include <iostream>
#include <chrono>

uint64_t getTimeHost(void)
{
  std::chrono::system_clock::time_point t = std::chrono::system_clock::now();

  std::chrono::system_clock::duration t_s = t.time_since_epoch();

  //t_us:  clock period(1l/1000000l s)    time interval(t_s)
  //to Calculate the number of clock cycles
  std::chrono::duration<uint64_t, std::ratio<1l, 1000000l>> t_us = 
    std::chrono::duration_cast<std::chrono::duration<uint64_t, std::ratio<1l, 1000000l>>>(t_s);
  
  return t_us.count();
}

int main(void)
{
    std::cout << getTimeHost() << std::endl;
    return 0;
}