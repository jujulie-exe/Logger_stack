#ifndef LOGGER_H
#define LOGGER_H
#include <ctime>
#include <cstdio>
#include <unistd.h>



class Logger
{
   public:
	enum Level {
        DEBUG = 0,
        INFO = 1,
        WARNING = 2,
        ERROR = 3,
    };
       /*♡♡♡♡♡♡♡♡♡♡♡CTOR♡♡♡♡♡♡♡♡♡♡♡♡♡*/
 
       /*♡♡♡♡♡♡♡♡♡♡♡GETTER♡♡♡♡♡♡♡♡♡♡♡♡♡*/
 
       /*♡♡♡♡♡♡♡♡♡♡♡FT♡♡♡♡♡♡♡♡♡♡♡♡♡*/
	   static void log(int lvl, const char *msg);
	   static void setLevelLog(Level level);
 
       /*♡♡♡♡♡♡♡♡♡♡♡OPERATOR♡♡♡♡♡♡♡♡♡♡♡♡♡*/
 
       /*♡♡♡♡♡♡♡♡♡♡♡DTOR♡♡♡♡♡♡♡♡♡♡♡♡♡*/
  private:
	   ////♡♡♡♡♡♡♡♡♡♡♡DELETE♡♡♡♡♡♡♡♡♡♡♡
       Logger& operator=(Logger const & rsh) = delete;
       Logger() = delete;  //cannon
       Logger(int level) = delete;  //cannon
       Logger(Logger const & src)   = delete;
       virtual ~Logger() = delete;
	   ////
	   inline static Level _levelLogger = DEBUG;

	   inline constexpr static const char* RESET    = "\033[0m";
	   inline constexpr static const char* GREEN    = "\033[32m";
	   inline constexpr static const char* BLUE     = "\033[34m";
	   inline constexpr static const char* YELLOW   = "\033[33m";
	   inline constexpr static const char* RED      = "\033[31m";
	   inline constexpr static const char* CRITICAL = "\033[31m";
	   inline constexpr static const char* PURPLE   = "\033[36m";

	/* enum Level {
        DEBUG = 0,
        INFO = 1,
        WARNING = 2,
        ERROR = 3,
    };*/

	   inline static  const char* level_color[] = {
			BLUE,     // DEBUG
			GREEN,   // INFO
			YELLOW,  // WARNING
			RED,     // ERROR
	   };
	   inline static const char *level_label[] = {
		   "DEBUG",
		   "INFO",
		   "WARNING",
		   "ERROR",
	   };
	

};

// std::ostream &operator<<(std::ostream &o, const Logger &rhs);
#endif // LOGGER_H

