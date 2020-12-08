#include <bits/stdc++.h>// include basic c++ liraries
#include <mlpack/methods/kmeans/kmeans.hpp>// mlpack library for k-means
#include <armadillo>//ml pack is dependent on armadillo

Using namespace std;

int main() {

    int k = 2; //amount of clusters
    int dim = 2;//dimensionality of program
    int samples = 50; 
    int max_iter = 10;//maximum number of iterations

    arma::mat data(dim, samples, arma::fill::zeros);

    // create data
    int i = 0;
    for(; i < samples / 2; ++i) {
        data.col(i) = arma::vec({1, 1}) + 0.25*arma::randn<arma::vec>(dim);
    }
    for(; i < samples; ++i) {
        data.col(i) = arma::vec({2, 3}) + 0.25*arma::randn<arma::vec>(dim);
    }

    //cluster the data
    arma::Row<size_t> clusters;
    arma::mat centroids;

    mlpack::kmeans::KMeans<> mlpack_kmeans(max_iter);
    mlpack_kmeans.Cluster(data, k, clusters, centroids);

    centroids.print("Centroids:");


}