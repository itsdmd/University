#ifndef VEHICLE_H
#define VEHICLE_H

class Vehicle {
	protected:
		float m_load = 0.0f;						// Goods' weight. (kg)
		float m_fuelAmount = 0.0f;					// (liters)
		float m_baseFuelCons = 0.0f;				// (liters/km)
		float m_fuelConsPerKg = 0.0f;				// Fuel consumption per kg of goods. (liters/kg)
		float m_travelDist = 0.0f;					// (km)

	public:
		void addLoad(float kg);
		void rmvLoad(float kg);

		void addFuel(float liters);
		void traverse(float km);

		float getFuelAmount() const;
};

class Motorbike: public Vehicle {
	public:
		Motorbike();
};

class Truck: public Vehicle {
	public:
		Truck();
};

#endif