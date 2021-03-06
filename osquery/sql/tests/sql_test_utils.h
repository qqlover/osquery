// Copyright (c) Facebook, Inc. and its affiliates. All Rights Reserved
#include <osquery/core.h>
#include <osquery/registry_interface.h>
#include <osquery/sql.h>
#include <osquery/sql/sqlite_util.h>
#include <osquery/utils/info/platform_type.h>

namespace osquery {

const std::string kTestQuery{"SELECT * FROM test_table"};

// Starting with the dataset returned by createTestDB(), getTestDBResultStream
// returns a vector of std::pair's where pair.first is the query that would
// need to be performed on the dataset to make the results be pair.second
std::vector<std::pair<std::string, QueryData>> getTestDBResultStream();

// getTestDBExpectedResults returns the results of kTestQuery of the table that
// initially gets returned from createTestDB()
QueryData getTestDBExpectedResults();

// getSerializedRowColumnNames returns a vector of test column names that
// are in alphabetical order. If unordered_and_repeated is true, the
// vector includes a repeated column name and is in non-alphabetical order
ColumnNames getSerializedRowColumnNames(bool unordered_and_repeated);

// getSerializedRow() return an std::pair where pair->first is a string which
// should serialize to pair->second. pair->second should deserialize
// to pair->first
std::pair<JSON, Row> getSerializedRow(bool unordered_and_repeated = false);

// getSerializedQueryData() return an std::pair where pair->first is a string
// which should serialize to pair->second. pair->second should
// deserialize to pair->first. getSerializedQueryDataWithColumnOrder
// returns a pair where pair->second is a tree that has a repeated column and
// the child nodes are not in alphabetical order
std::pair<JSON, QueryData> getSerializedQueryData();
std::pair<JSON, QueryData> getSerializedQueryDataWithColumnOrder();
std::pair<std::string, QueryData> getSerializedQueryDataJSON();

// getSerializedDiffResults() return an std::pair where pair->first is a string
// which should serialize to pair->second. pair->second should
// deserialize to pair->first
std::pair<JSON, DiffResults> getSerializedDiffResults();
std::pair<std::string, DiffResults> getSerializedDiffResultsJSON();

// getSerializedQueryLogItem() return an std::pair where pair->first
// is a string which should serialize to pair->second. pair->second
// should deserialize to pair->first
std::pair<JSON, QueryLogItem> getSerializedQueryLogItem();
std::pair<std::string, QueryLogItem> getSerializedQueryLogItemJSON();

} // namespace osquery
