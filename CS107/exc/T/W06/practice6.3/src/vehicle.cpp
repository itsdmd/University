#include "vehicle.h"

/// ------------------------------------------------------------------------ ///
///                                  Vehicle                                 ///
/// ------------------------------------------------------------------------ ///
void Vehicle::addGoodsWeight(float kg) {
	this->m_goodsWeight += kg;

	return;
}

void Vehicle::rmvGoodsWeight(float kg) {
	this->m_goodsWeight -= kg;

	return;
}

void Vehicle::addFuel(float liters) {
	this->m_fuelAmount += liters;

	return;
}

void Vehicle::traverse(float km) {
	this->m_travelDistance += km;
	this->m_fuelAmount -= ((this->m_baseFuelConsumption * km)
						   + (this->m_fuelConsumptionPerKgOfGoods * this->m_goodsWeight));

	return;
}

float Vehicle::getFuelAmount() const {
	return this->m_fuelAmount;
}

/// ------------------------------------------------------------------------ ///
///                                Derivatives                               ///
/// ------------------------------------------------------------------------ ///
Motorbike::Motorbike() {
	this->m_baseFuelConsumption = 0.02f;
	this->m_fuelConsumptionPerKgOfGoods = 0.01f;

	return;
}

Truck::Truck() {
	this->m_baseFuelConsumption = 0.2f;
	this->m_fuelConsumptionPerKgOfGoods = 0.001f;

	return;
}