#include "vehicle.h"

/// ------------------------------------------------------------------------ ///
///                                  Vehicle                                 ///
/// ------------------------------------------------------------------------ ///
// Add a weight of goods to the vehicle
void Vehicle::addLoad(float kg) {
	this->m_load += kg;

	return;
}

// Remove a weight goods from the vehicle
void Vehicle::rmvLoad(float kg) {
	this->m_load -= kg;

	return;
}

void Vehicle::addFuel(float liters) {
	this->m_fuelAmount += liters;

	return;
}

// Run the vehicle a length of km
void Vehicle::traverse(float km) {
	this->m_travelDist += km;
	this->m_fuelAmount -= ((this->m_baseFuelCons + (this->m_fuelConsPerKg * this->m_load)) * km);

	return;
}

float Vehicle::getFuelAmount() const {
	return this->m_fuelAmount;
}

/// ------------------------------------------------------------------------ ///
///                                Derivatives                               ///
/// ------------------------------------------------------------------------ ///
Motorbike::Motorbike() {
	this->m_baseFuelCons = 0.02f;
	this->m_fuelConsPerKg = 0.01f;

	return;
}

Truck::Truck() {
	this->m_baseFuelCons = 0.2f;
	this->m_fuelConsPerKg = 0.001f;

	return;
}