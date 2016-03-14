#include "hssdatabase.h"
#include "../hss_global.h"

HSSDatabase::HSSDatabase() :
    _db{HSS_DATABASE_F}
{

}

bool HSSDatabase::isUsernamePWDCorrect(const std::string &username,
                                       const std::string &pwd)
{
    SQLite::Statement query(_db, "SELECT COUNT(*) FROM HSS_USER WHERE ID = ? AND PW = ?");
    query.bind(1, username);
    query.bind(2, pwd);

    while (query.executeStep())
    {
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

    while (query.executeStep())
    {
        int res = query.getColumn(0);
        if (res) {
            return true;
        }
    }

    return false;
}
