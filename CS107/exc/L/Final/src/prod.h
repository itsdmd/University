#ifndef PROD_H
#define PROD_H

#include <string>
#include <vector>

using std::string;
using std::vector;

class Prod {
	protected:
		string m_code;
		string m_name;
		string m_mnft;				  // manufacurer

	public:
		Prod() {
			this->m_code = "";
			this->m_name = "";
			this->m_mnft = "";
		};
	
		string getCode() const { return this->m_code; }
		string getName() const { return this->m_name; }
		string getMnft() const { return this->m_mnft; }

		void setCode(const string& code) { this->m_code = code; }
		void setName(const string& name) { this->m_name = name; }
		void setMnft(const string& mnft) { this->m_mnft = mnft; }

		virtual double calcPrice() = 0;
		virtual void printInfo() = 0;
};

class Desktop: public Prod {
	private:
		vector<string> m_cpnts;				  // components
		vector<double> m_price;				  // prices of components (positional-related with m_cpnts)

	public:
		Desktop();
		Desktop(const string& code, const string& name, const string& mnft, const vector<string>& cpnts, const vector<double>& price);
	
		double calcPrice() override;
		
		vector<string> getCpnts() const { return this->m_cpnts; }
		vector<double> getPrice() const { return this->m_price; }

		void addCpnt();
		void addCpnt(const vector<string>& cpnts, const vector<double>& price);
		void rmvCpnt(const string& cpnt);
		
		void printInfo() override;
};

class Laptop: public Prod {
	private:
		double m_facPrice;				  // facory price

	public:
		Laptop();
		Laptop(const string& code, const string& name, const string& mnft, const double& facPrice);
	
		double calcPrice() override;
		
		double getFacPrice() const { return this->m_facPrice; }

		void setFacPrice(const double& facPrice) { this->m_facPrice = facPrice; }
		
		void printInfo() override;
};

class ProdList {
	private:
		vector<Prod*> m_prods;
	
	public:
		ProdList();
		~ProdList();
		
		void addProds();
		
		void queryByMnft();
		
		void sortByPriceDes();
		
		double calcTotalPrice();
		
		void printList();
};

#endif