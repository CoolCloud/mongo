// cloner.h - copy a database (export/import basically)

/**
 *    Copyright (C) 2011 10gen Inc.
 *
 *    This program is free software: you can redistribute it and/or  modify
 *    it under the terms of the GNU Affero General Public License, version 3,
 *    as published by the Free Software Foundation.
 *
 *    This program is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU Affero General Public License for more details.
 *
 *    You should have received a copy of the GNU Affero General Public License
 *    along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "jsobj.h"

namespace mongo {
    
    /**
     * @param slaveOk     - if true it is ok if the source of the data is !ismaster.
     * @param useReplAuth - use the credentials we normally use as a replication slave for the cloning
     * @param snapshot    - use $snapshot mode for copying collections.  note this should not be used when it isn't required, as it will be slower.
     *                      for example repairDatabase need not use it.
     */
    bool cloneFrom(const char *masterHost, string& errmsg, const string& fromdb, bool logForReplication,
                   bool slaveOk, bool useReplAuth, bool snapshot, bool mayYield,
                   bool mayBeInterrupted);

    bool copyCollectionFromRemote(const string& host, const string& ns, const BSONObj& query, string& errmsg, bool logForRepl, bool mayYield, bool mayBeInterrupted);

} // namespace mongo
