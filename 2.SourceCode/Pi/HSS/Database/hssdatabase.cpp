#include "hssdatabase.h"
#include "../hss_global.h"
#include <json.hpp>

HSSDatabase::HSSDatabase() :
    _db{HSS_DATABASE_F, SQLITE_OPEN_READWRITE}
{

}

bool HSSDatabase::isUsernamePWDCorrect(const std::string &username,
                                       const std::string &pwd)
{
    SQLite::Statement query(_db, "SELECT COUNT(*) FROM HSS_USER WHERE ID = ? AND PW = ?");
    query.bind(1, username);
    query.bind(2, pwd);

    while (query.executeStep()) {
        int res = query.getColumn(0);
        if (res) {
            return true;
        }
    }

    return false;
}

bool HSSDatabase::changePWD(const std::string &username,
                            const std::string &oldpwd,
                            const std::string &newpwd)
{
    if (!isUsernamePWDCorrect(username, oldpwd)) {
        return false;
    }

    SQLite::Statement query(_db, "UPDATE HSS_USER SET PW = ? WHERE ID = ?");
    query.bind(1, newpwd);
    query.bind(2, username);

    return !!query.exec();
}

void HSSDatabase::writeLog(const std::string &log)
{
    SQLite::Statement   query(_db, "INSERT INTO HSS_Activity (Timestamp, Activity) VALUES (?,?);");

    //TODO
    query.bind(1, "12:00");
    query.bind(2, log);

    while (query.executeStep()) {};

}

const std::string HSSDatabase::getAllCameraInfo()
{
    nlohmann::json js = nlohmann::json::array();
    SQLite::Statement query(_db, "SELECT * FROM HSS_Camera;");

    while (query.executeStep()) {
        std::string name = query.getColumn(0);
        std::string url = query.getColumn(1);
        js.push_back(nlohmann::json{
                         {"name", name},
                         {"url", url}
                     });
    }

    return js.dump();
}

const std::string HSSDatabase::getActivityLog()
{
    nlohmann::json js = nlohmann::json::array();
    SQLite::Statement query(_db, "SELECT * FROM HSS_Activity;");

    while (query.executeStep()) {
        std::string timestamp = query.getColumn(0);
        std::string activity = query.getColumn(1);
        js.push_back(nlohmann::json{
                         {"timestamp", timestamp},
                         {"activity", activity}
                     });
    }

    return js.dump();

}
