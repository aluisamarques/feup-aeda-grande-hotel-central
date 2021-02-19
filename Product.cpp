//
// Created by aluis on 30/10/2020.
//

#include "Product.h"

#include <string>

using namespace std;

/**
        * Class constructor
    */
Product::Product(string type){ this -> type = type; } // produtos comprados para guardar no stock

/**
        * Class constructor
    */
Product::Product(string type, int quality, int price){ //produtos para comprar ao fornecedor
    this -> quality = quality;
    this -> price = price;
    this-> type = type;
}

/**
        * Class Operator <
    */
bool Product::operator<(const Product &product) {
    if (price < product.price) return true;
    if (price > product.price) return false;
    return (quality > product.quality);
}

//getters and setters
/**
        * Return string type
    */
std::string Product::getType() const {
    return type;
}

/**
        * Return int price
    */
int Product::getPrice() const {
    return price;
}

/**
        * Return int quality
    */
int Product::getQuality() const {
    return quality;
}

/**
        * Set the product's type as equal to the argument
    */
void Product::setType(std::string type) {
    this-> type = type;
}

/**
        * Set the product's quality as equal to the argument
    */
void Product::setQuality(int quality) {
    this -> quality = quality;
}

/**
        * Set the product's price as equal to the argument price
    */
void Product::setPrice(int price) {
    this -> price = price;
}
