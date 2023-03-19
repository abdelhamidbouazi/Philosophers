# Philosophers

This is a solution to the classic Dining Philosophers problem using multithreading in C. The program simulates a group of philosophers who alternate between thinking and eating. They sit at a round table with a limited number of forks, and must use the forks on either side of their plates to eat. The challenge is to avoid deadlock and starvation.

## Usage

To compile the program, run `make`. Then, run the program with the following command:

./philo [number_of_philosophers] [time_to_die] [time_to_eat] [time_to_sleep] [number_of_times_each_philosopher_must_eat (optional)]

## For example:

./philo 5 800 200 200

## Author

Created by Abdelhamid Bouazi.
