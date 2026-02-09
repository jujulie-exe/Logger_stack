#include "../include/Logger.hpp"

//Logger::Level Logger::_levelLogger = Logger::DEBUG;       /*♡♡♡♡♡♡♡♡♡♡♡CTOR♡♡♡♡♡♡♡♡♡♡♡♡♡*/

       /*♡♡♡♡♡♡♡♡♡♡♡GETTER♡♡♡♡♡♡♡♡♡♡♡♡♡*/
 
       /*♡♡♡♡♡♡♡♡♡♡♡FT♡♡♡♡♡♡♡♡♡♡♡♡♡*/
void Logger::log(int lvl, const char *msg)
{
    if (static_cast<int>(_levelLogger) > lvl)
        return;

    char buffer[526];
    int offset = 0;

    time_t now = time(NULL);
    struct tm tm;
    localtime_r(&now, &tm);
	int fd = 1;
    if (static_cast<int>(ERROR) == lvl){
		fd = 2;
	}

    offset += snprintf(buffer + offset, sizeof(buffer) - offset,
                       "%02d:%02d:%02d ",
                       tm.tm_hour, tm.tm_min, tm.tm_sec);

    const char* color = level_color[lvl];
    const char* label = level_label[lvl];

    offset += snprintf(buffer + offset, sizeof(buffer) - offset,
                       "%s%-5s%s  %s ",
                       color, label, RESET, msg);
    const char* heart = "♡";
    int invisibile = strlen(color) + strlen(RESET);
    int visibile = strlen(buffer) - invisibile;
    while (visibile <= HEARTS_IN_LINE  && (offset + sizeof("♡")) < (int)sizeof(buffer)){
        offset += snprintf(buffer + offset, sizeof(buffer) - offset, "%s", heart);
        visibile++;
    }
    offset += snprintf(buffer + offset, sizeof(buffer) - offset, "\n");
    write(fd, buffer, offset);
}

void Logger::setLevelLog(Level level){

	if (level > ERROR || level < DEBUG){
		return;
	}
	_levelLogger = level;
	return ;
}
 
       /*♡♡♡♡♡♡♡♡♡♡♡OPERATOR♡♡♡♡♡♡♡♡♡♡♡♡♡*/

       /*♡♡♡♡♡♡♡♡♡♡♡DTOR♡♡♡♡♡♡♡♡♡♡♡♡♡*/

/* std::ostream &operator<<(std::ostream &o, const Logger &rhs)
{
   o << rhs.getName() << std::endl;
   return o;
} */

