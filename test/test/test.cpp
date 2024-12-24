#define CATCH_CONFIG_COUNTER
#define CATCH_CONFIG_MAIN
#include <catch.hpp>
#include "database_manager.h"

#pragma comment(lib, "WS2_32.lib")

TEST_CASE("test_storage")
{
    DatabaseManager db{};
    vector <abstracts::Storage> storages;
    db.save(storages);
    abstracts::Storage storage{ 1,{5,6} };
    storages.push_back(storage);
    db.save(storages);
    storages.clear();
    db.read(storages);
    REQUIRE(storages.size() == 1u);
    REQUIRE(storages[0].id == storage.id);
}

TEST_CASE("test_couriers")
{
    DatabaseManager db{};

    vector <abstracts::Storage> storages;
    db.save(storages);
    abstracts::Storage storage{ 1,{5,6} };
    storages.push_back(storage);
    db.save(storages);

    vector <abstracts::Courier> couriers;
    db.save(couriers);
    abstracts::Courier courier{
            .id=2,
         .speed_kmh=5.5,
         .storage_id=storage.id,
         .pos = {1,1} };
    couriers.push_back(courier);
    db.save(couriers);
    couriers.clear();
    db.read(couriers);
    REQUIRE(couriers.size() == 1u);
    REQUIRE(couriers[0].id == courier.id);
}
