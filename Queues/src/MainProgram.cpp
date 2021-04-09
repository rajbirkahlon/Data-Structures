

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <cmath>
#include <queue>

#include "Simulation.h"


using namespace std;

void setSimulationParameters(int& sTime, int& numOfServers,
							 int& transTime,
							 int& tBetweenCArrival);
bool isCustomerArrived(double arvTimeDiff);

void generateStatistics(serverListType& serverList,
						queue<customerType>& custQ,
						int numOfCustArrived,
						int waitTimeServedCustomers);
void runSimulation();

void updateCustQueue(queue<customerType>& custQ);

/* int main()
{
	runSimulation();

	return 0;
} */

void setSimulationParameters(int& sTime, int& numOfServers,
							 int& transTime,
							 int& tBetweenCArrival)
{
	cout << "Enter simulation time: ";
	cin >> sTime;
	cout << endl;

	cout << "Enter number of servers: ";
	cin >> numOfServers;
	cout << endl;

	cout << "Enter transaction time: ";
	cin >> transTime;
	cout << endl;

	cout << "Enter time between customers arrival: ";
	cin >> tBetweenCArrival;
	cout << endl;
}

bool isCustomerArrived(double arvTimeDiff)
{
	double value;

	value = static_cast<double> (rand()) / static_cast<double>(RAND_MAX);

	return (value > exp(- 1.0/arvTimeDiff));
}

void runSimulation()
{
	int simulationTime;
	int numberOfServers;
	int transactionTime;
	int timeBetweenCustomerArrival;

	queue<customerType> customerQueue;

	customerType customer;

	int custNumber = 0;

	int totalWaitTimeServedCustomers = 0;
	int totalWaitTime = 0;
	int numberOfCustomersServed = 0;
	int customersLeftInServers = 0;
	int clock = 0;
	int serverID;

	setSimulationParameters(simulationTime, numberOfServers,
		        transactionTime, timeBetweenCustomerArrival);

	serverListType serverList(numberOfServers);

	for (clock = 1; clock <= simulationTime; clock++)
	{
		serverList.updateServers(cout);

		if (!customerQueue.empty())
			updateCustQueue(customerQueue);

		if (isCustomerArrived(timeBetweenCustomerArrival))
		{
			/**************
			 * TODO: Implement what happens when a customer arrives
			 **************/
			cout << "Customer number " << custNumber
				 << " arrived at time unit " << clock << endl;
		}

		serverID = serverList.getFreeServerID();
		if (serverID != -1 && !customerQueue.empty())
		{
			/**************
			 * TODO: Implement what happens when a server is free
			 **************/
		}
	}

	cout << endl;

	cout << "Simulation ran for " << simulationTime
		 << " time units" << endl;
	cout << "Number of servers: " << numberOfServers << endl;
	cout << "Average transaction time: "
		 << transactionTime << endl;
	cout << "Average arrival time difference between customers: "
		 << timeBetweenCustomerArrival << endl;

	generateStatistics(serverList, customerQueue,
					   custNumber, totalWaitTimeServedCustomers);
}

void generateStatistics(serverListType& serverList,
						queue<customerType>& custQ,
						int numOfCustArrived,
						int waitTimeServedCustomers)
{
	int customersLeftInQueue = 0;

	int totalWaitTime = waitTimeServedCustomers;

	customerType customer;

	while (!custQ.empty())
	{
		customer = custQ.front();
		custQ.pop();
		totalWaitTime = totalWaitTime + customer.getWaitingTime();
		customersLeftInQueue++;
	}

			//Find number of customers left in servers
	int customersLeftInServers = serverList.getNumberOfBusyServers();
			//Find number of customers completely served
	int numberOfCustomersServed = numOfCustArrived -
								  customersLeftInServers -
							      customersLeftInQueue;

	double averageWaitTime = 0;

	cout << "Total wait time: " << totalWaitTime << endl;
	cout << "The number of customers who completed a transaction: "
		 << numberOfCustomersServed << endl;
	cout << "The number of customers left in the servers: "
		 << customersLeftInServers << endl;
	cout << "The number of customers left in the queue: " << customersLeftInQueue
		 << endl;

	if (numOfCustArrived > 0)  // If number of customers arrived is > 0
		averageWaitTime = (static_cast<double>(totalWaitTime)) / numOfCustArrived;

	cout << fixed << showpoint;
	cout << setprecision(2);
	cout << "Average wait time: " << averageWaitTime << endl;
	cout << "************** END SIMULATION *************" << endl;

}

void updateCustQueue(queue<customerType>& custQ)
{
	customerType cust;

	cust.setWaitingTime(-1);
	int wTime = 0;

	custQ.push(cust);

	while (wTime != -1)
	{
		cust = custQ.front();
		custQ.pop();
		wTime = cust.getWaitingTime();
		if (wTime == -1)
			break;
		cust.incrementWaitingTime();
		custQ.push(cust);
	}

}
