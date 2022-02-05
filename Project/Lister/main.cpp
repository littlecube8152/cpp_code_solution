#include <algorithm>
#include <chrono>
#include <cmath>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <thread>
#include <utility>
#include <vector>

class Lister
{
    using time_point = std::chrono::time_point<std::chrono::system_clock>;
    using day = std::chrono::duration<long long, std::ratio<86400>>;

private:
    // Constant for terminal colors, and some useful operations.
    const std::string reset = "\033[0m",
                      bold = "\033[1m",
                      red = "\033[31m",
                      green = "\033[32m",
                      yellow = "\033[33m",
                      grey = "\033[90m",
                      erase_line = "\33[2K",
                      move_up = "\033[A",
                      line_start = "\r",
                      tab = "    ";

    // Constant error and respond for commands
    const std::string success = green + "Operation Successful" + reset,
                      none = "",
                      errorNoCommand = red + "No command found. Are you doing some black magic?" + reset,
                      errorAddArgument = red + "Usage: `add cd [year] [month] [day] [name]` or `add todo [name]` " + reset,
                      errorDeleteArgument = red + "Usage: `delete {cd|todo} [id]`" + reset,
                      errorNotCommand = red + "Unknown Command, use help to get further information." + reset,
                      errorHelpNotCommand = red + "Unknown Command. Are you sure you are asking right thing?" + reset,
                      helpArgument = yellow + "Avaliable command: add, delete, refresh, help. Use `help [command]` to get further information." + reset,
                      helphelpArgument = yellow + "Why you are helping an help? This makes non-sense!" + reset,
                      addArgument = yellow + "Add an item in to list. Usage: `add cd [year] [month] [day] [name]` or `add todo [name]`" + reset,
                      deleteArgument = yellow + "Delete an item in the list. Usage: `delete {cd|todo} [id]`" + reset,
                      refreshArgument = yellow + "Refresh. Usage: `refresh`" + reset;

    // Constant for line width
    const int line_width = 20;

    // Constant error and respond for commands
    const std::string hasPassed = "has ended.",
                      isToday = bold + "is today's event !!!" + reset,
                      isTomorrow = bold + "still have " + red + "1" + reset + " day.",
                      remainPrefix = "still have ",
                      remainSuffix = " days." + reset;
    const long long warningDay = 7, noticeDay = 30;

    // Count for line, so render will be easier to re-render.
    int lines_counter = 0;

    // Command Output, so this will be keeped when rerendered.
    std::string commandOutput = none;

    // Two lists, as their name.
    std::vector<std::pair<time_point, std::string>> count_down, todo_list;

    // Useful function to convert year, month, day structure to std::chrono::system_clock::time_point.
    time_point convert_date_to_time_point(int year, int month, int day)
    {
        std::tm date_tm;
        date_tm.tm_sec = 59;
        date_tm.tm_min = 59;
        date_tm.tm_hour = 23;
        date_tm.tm_year = year - 1900;
        date_tm.tm_mon = month - 1;
        date_tm.tm_mday = day;
        time_t date_time_t = mktime(&date_tm);
        time_point date_time_point = std::chrono::system_clock::from_time_t(date_time_t);
        return date_time_point;
    }

    std::string get_time_point_string(time_point tp)
    {
        std::time_t time_tp = std::chrono::system_clock::to_time_t(tp);

        std::stringstream ss;
        ss << std::put_time(localtime(&time_tp), "%Y %m %d");
        return ss.str();
    }

    void dump_data()
    {
        std::ofstream fout("data.txt");
        for (auto i : count_down)
            fout << "C " << get_time_point_string(i.first) << " " << i.second << '\n';
        for (auto i : todo_list)
            fout << "A " << i.second << '\n';
        fout << std::flush;
    }

    void get_data()
    {
        std::ifstream fin("data.txt");
        char c;
        int year, month, day;
        std::string name;
        while (fin >> c)
        {
            if (c == 'C')
            {
                fin >> year >> month >> day >> name;
                add(0, name, year, month, day);
            }
            else if (c == 'A')
            {
                fin >> name;
                add(1, name);
            }
        }
    }

public:
    // Initialize the class Lister. Return 0 when operated successfully.
    int init()
    {
        count_down.clear();
        todo_list.clear();
        get_data();
        int lines_counter = 0;
        std::string commandOutput = none;
        render();
        return 0;
    }

    // Render count-down list and to-do list,
    int render()
    {
        //Clears Output
        for (int i = 1; i <= lines_counter; i++)
            std::cout << line_start << erase_line << move_up;
        lines_counter = 1;
        std::cout << '\n';

        //Render count-down list
        std::cout << bold << "Count-down:\n"
                  << reset;
        lines_counter++;

        for (int i = 0; i < count_down.size(); i++)
        {
            std::cout << std::setw(3);
            double days = std::floor(std::chrono::duration_cast<day>(count_down[i].first - std::chrono::system_clock::now()).count());
            if (days < 0)
                std::cout << grey << tab << std::setw(3) << i << " - " << std::setw(0) << count_down[i].second << std::string(line_width - count_down[i].second.length(), ' ') << hasPassed << reset;
            else if (days == 0)
                std::cout << bold << tab << std::setw(3) << i << " - " << std::setw(0) << count_down[i].second << std::string(line_width - count_down[i].second.length(), ' ') << isToday;
            else if (days == 1)
                std::cout << bold << tab << std::setw(3) << i << " - " << std::setw(0) << count_down[i].second << std::string(line_width - count_down[i].second.length(), ' ') << isTomorrow;
            else if (days <= warningDay)
                std::cout << tab << std::setw(3) << i << " - " << std::setw(0) << count_down[i].second << std::string(line_width - count_down[i].second.length(), ' ') << remainPrefix << yellow << days << reset << remainSuffix;
            else if (days <= noticeDay)
                std::cout << tab << std::setw(3) << i << " - " << std::setw(0) << count_down[i].second << std::string(line_width - count_down[i].second.length(), ' ') << remainPrefix << green << days << reset << remainSuffix;
            else
                std::cout << tab << std::setw(3) << i << " - " << std::setw(0) << count_down[i].second << std::string(line_width - count_down[i].second.length(), ' ') << remainPrefix << days << remainSuffix;

            std::cout << "    " << get_time_point_string(count_down[i].first) << '\n';
            lines_counter++;
        }
        std::cout << '\n';
        lines_counter++;

        //Render to-do list
        std::cout << bold << "TO-DO:\n"
                  << reset;
        lines_counter++;
        for (int i = 0; i < todo_list.size(); i++)
        {
            std::cout << tab << i << " -" << todo_list[i].second << "\n";
            lines_counter++;
        }
        std::cout << '\n';
        lines_counter++;
        std::cout << commandOutput << '\n';
        lines_counter++;

        return 0;
    }

    // Add an item in list, type 0 denotes count-down and type 1 denotes to-do.
    // event is what that event called and year, month, day is just as what they means.
    int add(int type, std::string event, int year = 2000, int month = 0, int day = 0)
    {
        switch (type)
        {
        case 0:
            count_down.emplace_back(std::make_pair(convert_date_to_time_point(year, month, day), event));
            std::sort(count_down.begin(), count_down.end());
            break;
        case 1:
            todo_list.emplace_back(std::make_pair(convert_date_to_time_point(year, month, day), event));
            std::sort(todo_list.begin(), todo_list.end());
            break;
        }

        return 0;
    }

    // Remove an item in list, type 0 denotes count-down and type 1 denotes to-do.
    // id is the numbering on the list.
    int remove(int type, int id)
    {
        switch (type)
        {
        case 0:
            count_down.erase(count_down.begin() + id);
            break;
        case 1:
            todo_list.erase(todo_list.begin() + id);
            break;
        }

        return 0;
    }

    // Handle command input, returns 0 when not reciving any error.
    // Returns 1 when command isn't valid, and returns 2 when user asks to exit.
    int command_input()
    {
        // Put command line into stringstream, so that will make analyze more easier.
        std::string command_line;
        std::getline(std::cin, command_line);
        std::cout << line_start << erase_line;
        std::stringstream command_line_stream;
        command_line_stream.clear();
        command_line_stream << command_line;

        if (command_line == "")
        {
            lines_counter++;
            render();
            return 1;
        }

        // Analyze command
        std::string main_command, sub_command, arg_name;
        int arg_year, arg_month, arg_day, arg_id;
        bool valid_command = true;
        if (command_line_stream >> main_command)
        {
            // Get help of some commands.
            if (main_command == "help")
            {
                if (command_line_stream >> sub_command)
                {
                    if (sub_command == "help")
                        commandOutput = helphelpArgument;
                    else if (sub_command == "add")
                        commandOutput = addArgument;
                    else if (sub_command == "delete")
                        commandOutput = deleteArgument;
                    else if (sub_command == "refresh")
                        commandOutput = refreshArgument;
                    else
                    {
                        commandOutput = errorHelpNotCommand;
                        valid_command = false;
                    }
                }
                else
                    commandOutput = helpArgument;
            }
            // Add an new item
            else if (main_command == "add")
            {
                bool local_valid = true;
                if (!(command_line_stream >> sub_command))
                    local_valid = false;
                if (sub_command != "todo" && sub_command != "cd")
                    local_valid = false;

                if (sub_command == "cd")
                {
                    if (!(command_line_stream >> arg_year))
                        local_valid = false;
                    if (!(command_line_stream >> arg_month))
                        local_valid = false;
                    if (!(command_line_stream >> arg_day))
                        local_valid = false;
                }
                if (!(command_line_stream >> arg_name))
                        local_valid = false;
                
                if (arg_name == "")
                    local_valid = false;

                if (local_valid)
                {
                    commandOutput = success;
                    if (sub_command == "cd")
                        add(0, arg_name, arg_year, arg_month, arg_day);
                    else if (sub_command == "todo")
                        add(1, arg_name);
                }
                else
                {
                    commandOutput = errorAddArgument;
                    valid_command = false;
                }
            }
            // Delete an new item
            else if (main_command == "delete")
            {
                bool local_valid = true;
                if (!(command_line_stream >> sub_command))
                    local_valid = false;
                if (!(command_line_stream >> arg_id))
                    local_valid = false;
                if (sub_command != "todo" && sub_command != "cd")
                    local_valid = false;

                if (local_valid)
                {
                    commandOutput = success;
                    if (sub_command == "cd")
                        remove(0, arg_id);
                    else if (sub_command == "todo")
                        remove(1, arg_id);
                }
                else
                {
                    commandOutput = errorAddArgument;
                    valid_command = false;
                }
            }
            // Refresh
            else if (main_command == "refresh")
            {
                commandOutput = none;
            }
            // Exits program
            else if (main_command == "exit")
            {
                return 2;
            }
            else
            {
                commandOutput = errorNotCommand;
                valid_command = false;
            }
        }
        else
        {
            std::cout << errorNoCommand << '\n';
            valid_command = false;
        }

        lines_counter++;
        render();

        if (valid_command)
            return 0;
        else
            return 1;
    }

    // Handle command input service.
    // Keep input until end.
    void keep_command_input()
    {
        while (command_input() <= 1)
            continue;
        dump_data();
    }

    // Handle command input service.
    // Keep input until end.
    void keep_change_day_rerender()
    {
        while (1)
        {
            time_point thisDay = std::chrono::system_clock::now();
            time_point possiblePreviousDay = std::chrono::floor<day>(thisDay);
            if (thisDay != possiblePreviousDay)
            {
                render();
                std::this_thread::sleep_for(std::chrono::hours(23) + std::chrono::minutes(59));
            }
        }
    }
};

int main()
{
    Lister lister;
    lister.init();

    std::thread commandThread(&Lister::keep_command_input, std::ref(lister));
    //std::thread refreshThread(&Lister::keep_change_day_rerender, std::ref(lister));

    commandThread.join();
}