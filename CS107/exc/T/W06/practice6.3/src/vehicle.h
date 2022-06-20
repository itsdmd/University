#ifndef VEHICLE_H
#define VEHICLE_H

class Vehicle {
	protected:
		float m_goodsWeight = 0.0f;					// kg
		float m_fuelAmount = 0.0f;					// liters
		float m_fuelConsumptionPerKgOfGoods = 0.0f;	// liters/kg
		float m_baseFuelConsumption = 0.0f;			// liters/km
		float m_travelDistance = 0.0f;

	public:
		void addGoodsWeight(float kg);
		void rmvGoodsWeight(float kg);

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