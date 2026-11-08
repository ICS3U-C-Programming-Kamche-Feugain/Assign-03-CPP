// Copyright (c) 2026 Kamche All rights reserved.
// .
// Created by: Your Kamche
// Date: Nov 7, 2026
// This program ask the user for its age,
// time of day and status to calculate
// and give the passenger a train fare ticket.
#include <iostream>
#include <string>

int main() {
    // Welcome the passenger to my train station
    std::cout << "Welcome to Kamche's train station" << std::endl;
    std::cout << "Where everything is like a dream" << std::endl;

    // declare constants
    const float CHILD_FARE = 0.00;
    const float YOUTH_FARE = 2.50;
    const float STUDENT_FARE = 2.50;
    const float ADULT_FARE = 3.50;
    const float SENIOR_FARE = 2.00;
    const float PEAK_SURCHARGE = 0.50;

    // declare variables
    int age_input_int;
    std::string status;
    std::string time_of_day;
    float fare = 0.00;

    // Get passenger information
    std::string ageInputStr;
    std::cout << "Enter your age:";
    std::cin >> ageInputStr;
    std::cout << "\n";

    // Catch errors that may occur during user input
    try {
        // Convert user input to an integer
        age_input_int = std::stoi(ageInputStr);

        // Get status and time of day
        std::cout << "Are you a student? (yes/no): ";
        std::cin >> status;
        std::cout << "Enter the time of the day (peak or off-peak): ";
        std::cin >> time_of_day;

        // Calculate the fare ticket
        if (age_input_int >= 65) {
            fare = SENIOR_FARE;
        } else if (age_input_int < 12) {
            fare = CHILD_FARE;
        } else if (age_input_int <= 21) {
            fare = YOUTH_FARE;
        } else if (status == "yes") {
            fare = STUDENT_FARE;
        } else {
            fare = ADULT_FARE;
        }

        // Apply peak surcharge
        if (time_of_day == "peak" && age_input_int >= 12) {
            fare = fare + PEAK_SURCHARGE;
        }
        // Display results
        std::cout << "\nTRAIN FARE." << std::endl;
        std::cout << "Passenger age: " << age_input_int << std::endl;
        std::cout << "Status" << status << std::endl;
        std::cout << "Time of the day:" << time_of_day << std::endl;

        if (age_input_int < 12) {
            std::cout << "Total fare: Free" << std::endl;
        } else {
            std::cout << "The total fare is: $" << fare << std::endl;
        }
    }catch (const std::invalid_argument&) {
        std::cout << ageInputStr << " is an invalid entry."
                  << "Please enter a valid number for age. " << std::endl;
    }
    // Thank the passenger
    std::cout << "Thank you for traveling with us!!" << std::endl;
