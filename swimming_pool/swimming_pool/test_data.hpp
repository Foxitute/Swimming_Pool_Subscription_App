#pragma once
#ifndef test_data_hpp
#define test_data_hpp

#include <iostream>

#include "Repository_uow.hpp"

class test_data
{
private:
    Repository_uow* uow_;
    
public:
    test_data (Repository_uow* uow);
    
    void run ();
    void show ();
    
private:
    void add_locations () const;
    void add_subscriptions () const;
    void add_pools () const;
    void add_pool_subscriptions () const;
    void add_subs_histories () const;
    
    void show_locations ();
    void show_subscriptions ();
    void show_pools ();
    void show_pool_subscriptions ();
    void show_subs_histories ();
};

#endif /* test_data_hpp */
