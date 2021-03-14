/*
Read a sequence of double values into a vector.Think of each value as
the distance between two cities along a given route.Compute and print
the total distance(the sum of all distances).Fmdand print the smallest
and greatest distance between two neighboring cities.Fmdand print the
mean distance between two neighboring cities.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	vector<double>distances; // vector
	double sum_of_distances = 0.0; // sum memmory

	for (double distance = 0.0; cin >> distance; distances.push_back(distance)); // put in the vector all read in values of distances
	for (int i = 0; i < distances.size(); ++i) // count of sum
	{
		sum_of_distances += distances[i];
	}

	sort(distances.begin(), distances.end()); // sort all values

	cout << "the smallest distance: " << distances[0] << endl; // write out smallest
	cout << "the greatest distance: " << distances[distances.size()-1] << endl; // write out largest
	cout << "the sum of distances: " << sum_of_distances << endl; // write ouy the sum
	cout << "the mean of distances: " << sum_of_distances / distances.size() << endl; // write out the mean
}