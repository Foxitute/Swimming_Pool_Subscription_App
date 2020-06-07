#include <iostream>

#include "app_setting_manager.hpp"
#include "app_settings_initializer.hpp"
#include "Pool_repository.hpp"
#include "File_repository_uow.hpp"
#include "Repository_uow.hpp"
#include "Pool_serializer.hpp"
#include "test_data.hpp"

void enter_values (double& length, double& width, double& depth)
{
    std::cout << "Enter the pool's length\t: ";
    std::cin >> length;
    std::cout << "Enter the pool's width\t: ";
    std::cin >> width;
    std::cout << "Enter the pool's depth\t: ";
    std::cin >> depth;
    if (length == 0 || width == 0 || depth == 0)
        throw std::runtime_error("Some of measures were assigned uncorrectly!");
}

void enter_shape (size_t& choice)
{
    std::cout << "Do you want to count the volume of pool?" << std::endl
              << "Yes - 1, No - 0" << std::endl;
    std::cin >> choice;
    if (choice != 1) return;
    
    std::cout << "What is the shape of your pool: "    << std::endl
              << "1. Round\n2. Rectangle\n3. Square\n" << std::endl
              << "Enter your choice(1-3): ";
    std::cin >> choice;
}

void test()
{
    try
    {
        double length=0, width=0, depth=0;
        enter_values(length, width, depth);
        P_Shape shape (length,width,depth, Shapes::Undefined);
        size_t choice;
        enter_shape(choice);
        
        shape.choice_to_shape(choice);
        double volume = shape.calc_volume();
        std::cout <<"Volume is: "<< volume <<" m^3" << "\n\n";
        
        Pool pool ("My pool", &shape);
        Pool_serializer ser;
        std::cout << ser.to_string(&pool) << std::endl;
    }
    catch (std::exception const& ex)
    {
        std::cerr << "Something went wrong: " << ex.what() << std::endl;
    }
}

void init_test_data()
{
    // create an instance of Repository UnitOfWork
    Repository_uow* repositories = new File_repository_uow;

    // Create an instance of test_data class.
    // The test_data class takes the instance of repository_uow in constructor.
    test_data test(repositories);

    // Populate default values if no data
    test.run();

    // Display all collections
    test.show();
}

int main()
{
    // CHECK APP SETTINGS
    // add default values for required app settings if they are missed
    app_settings_initializer app_settings_initializer;
    app_settings_initializer.check_and_init_settings();

    // For testing purposes.
    // The method sets default values for all existing collections
    init_test_data();
    
//    {
//        test();
//        P_Shape* shape = new P_Shape(12,21,2,Shapes::Undefined);
//        Pool* a = new Pool("23", shape);
//
//        Pool_serializer ser;
//        std::cout << std::endl << ser.to_string(a) << std::endl;
//
//        std::cout << "1. " << a->serial_number_ << "\t2. "
//                  << Shapes::to_string(a->pshape_->shape_) << std::endl;
//
//        std::cout << std::endl << "Thank you for choosing our program!" << std::endl;
//    }
}

