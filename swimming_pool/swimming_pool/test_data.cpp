#include "test_data.hpp"

test_data::test_data (Repository_uow* uow)
    : uow_(uow) {}

void test_data::run ()
{
    add_locations();
    add_subscriptions();
    add_pools();
    add_pool_subscriptions();
    add_subs_histories();
}

void test_data::show ()
{
    show_locations();
    show_subscriptions();
    show_pools();
    show_pool_subscriptions();
    show_subs_histories();
}

        // METHODS FOR RUN FUNCTION
void test_data::add_locations () const
{
    // adds 1 test LOCATION and keeps it
    auto repository = uow_->get_location_repository();
    
    if (!repository->get_collection().empty()) {
        return;
    }
    
    auto location = new Location;
    location->name = "Poseidon";
    repository->add(location);
}

void test_data::add_subscriptions () const
{
    // adds 1 test SUBSCRIPTION and keeps it
    auto repository = uow_->get_subscription_repository();
    
    if (!repository->get_collection().empty()) {
        return;
    }
    
    auto sub = new Subscription;
    sub->name = "Elena Kazenelson";
    sub->effective_from = &date_time::parse("2020/06/07 TIME/11:08:14");
    sub->effective_to   = &date_time::parse("2020/08/23 TIME/03:59:59");
    sub->hours = 12;
    sub->max_unit_count = 4;
    sub->unit_title = "day";
    sub->type = "PayAsYouGo";
    repository->add(sub);
}

void test_data::add_pools () const
{
    // adds 1 test POOL and keeps it
    auto repository = uow_->get_pool_repository();
    
    if (!repository->get_collection().empty()) {
        return;
    }
      
    auto pool = new Pool;
    pool->serial_number_ = "1234567890";
    pool->pshape_ = new P_Shape(50.35, 20.1, 3.2, Shapes::Rectangle);
    
    repository->add(pool);
}

void test_data::add_pool_subscriptions () const
{
    // adds 1 test POOL_SUBSCRIPTION and keeps it
    auto repository = uow_->get_pool_subscription_repository();
    
    if (!repository->get_collection().empty()) {
        return;
    }
    
    auto pool_sub = new Pool_subscription;
    pool_sub->pool_id = 1;
    pool_sub->subscription_id = 1;
    pool_sub->effective_from = &date_time::now();
    pool_sub->effective_to = &date_time::parse("2022/11/17 TIME/12:00:00");
    pool_sub->created_at = &date_time::now();
    pool_sub->unit_count = 20;
    
    repository->add(pool_sub);
}

void test_data::add_subs_histories () const
{
    // adds 1 test SUBS_HISTORY and keeps it
    auto repository = uow_->get_subs_history_repository();
    
    if (!repository->get_collection().empty()) {
        return;
    }
    
    auto history = new Subs_history;
    history->Pool_subscription_id = 31;
    history->created_at = &date_time::now();
    history->units_used = 5;
    
    repository->add(history);
}



    // METHODS FOR SHOW FUNCTION
void test_data::show_locations ()
{
    // shows all test LOCATIONS in the console output
    auto entities = uow_->get_location_repository()->get_collection();
    
    std::cout << "       Locations        " << std::endl
              << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯" << std::endl;
    for (auto const& entity : entities)
    {
        std::cout << "ID:         " << entity->id_  << std::endl;
        std::cout << "Name:       " << entity->name << std::endl;
        std::cout << std::endl;
    }
}

void test_data::show_subscriptions ()
{
    // shows all test SUBSCRIPTIONS in the console output
    auto entities = uow_->get_subscription_repository()->get_collection();
    
    std::cout << "     Subscriptions      " << std::endl
              << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯" << std::endl;
    for (auto const& entity : entities)
    {
        std::cout << "ID:         " << entity->id_  << std::endl;
        std::cout << "Name:       " << entity->name << std::endl;
        std::cout << "Type:       " << entity->type << std::endl;
        std::cout << "From:       " << entity->effective_from->to_string() << std::endl;
        std::cout << "To:         " << entity->effective_to->to_string() << std::endl;
        std::cout << "Hours:      " << entity->hours << std::endl;
        std::cout << "Unit Title: " << entity->type << std::endl;
        std::cout << std::endl;
    }
}

void test_data::show_pools ()
{
    // shows all test POOLS in the console output
    auto entities = uow_->get_pool_repository()->get_collection();
    
    std::cout << "         Pools          " << std::endl
              << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯" << std::endl;
    for (auto const& entity : entities)
    {
        std::cout << "ID:         " << entity->id_            << std::endl;
        std::cout << "Number:     " << entity->serial_number_ << std::endl;
        std::cout << std::endl;
    }
}

void test_data::show_pool_subscriptions ()
{
    // shows all test POOL_SUBSCRIPTIONS in the console output
    auto entities = uow_->get_pool_subscription_repository()->get_collection();
    
    std::cout << "   Pool Subscriptions   " << std::endl
              << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯" << std::endl;
    for (auto const& entity : entities)
    {
        std::cout << "ID:         " << entity->id_                         << std::endl;
        std::cout << "Created at: " << entity->created_at->to_string()     << std::endl;
        std::cout << "Pool ID:    " << entity->pool_id                     << std::endl;
        std::cout << "Subs ID:    " << entity->subscription_id             << std::endl;
        std::cout << "From:       " << entity->effective_from->to_string() << std::endl;
        std::cout << "To:         " << entity->effective_to->to_string()   << std::endl;
        std::cout << "Unit Count: " << entity->unit_count                  << std::endl;
        std::cout << std::endl;
    }
}

void test_data::show_subs_histories ()
{
    // shows all test SUBS_HISTORIES in the console output
    auto entities = uow_->get_subs_history_repository()->get_collection();
    
    std::cout << "  Subscription History  " << std::endl
              << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯" << std::endl;
    for (auto const& entity : entities)
    {
        std::cout << "ID:         " << entity->id_                     << std::endl;
        std::cout << "Created at: " << entity->created_at->to_string() << std::endl;
        std::cout << "Card ID:    " << entity->Pool_subscription_id    << std::endl;
        std::cout << "Used:       " << entity->units_used              << std::endl;
        std::cout << std::endl;
    }
}
