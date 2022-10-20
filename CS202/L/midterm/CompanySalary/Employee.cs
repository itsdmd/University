using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using System.Text;

namespace CompanySalary
{
	public class Factory
	{
		public Factory() { }
		
		public List<string> FileReader(string fileDir)
		{
			return (new List<string>(File.ReadAllLines(fileDir)));
		}
		
		public List<IEmployee> Generate(string fileDir)
		{
			List<string> fileContent = FileReader(fileDir);
			List<string> employeesInfo = new List<string>();
			List<IEmployee> employees = new List<IEmployee>();

			int counter = 0;
			foreach (string line in fileContent)
			{
				switch (counter)
				{
					case 0:
						employeesInfo.Add(line);
						break;
					case 1:
						employeesInfo[employeesInfo.Count - 1] += line;
						break;
					case 2:
						employeesInfo[employeesInfo.Count - 1] += line;
						counter = -1;
						break;
					default:
						break;
				}

				counter++;
			}

			foreach (string employee in employeesInfo)
			{
				var tokens = employee.Split(" ", StringSplitOptions.RemoveEmptyEntries);
				string temp = "";
				string final = "";

				switch (tokens[0])
				{
					case "DailyEmployee:":
						employees.Add(new DailyEmployee());
						break;

					case "HourlyEmployee:":
						employees.Add(new HourlyEmployee());
						break;

					case "ProductEmployee:":
						employees.Add(new ProductEmployee());
						break;

					case "Manager:":
						employees.Add(new Manager());
						//// Create substring between '=' and '$'
						//temp = tokens[7].Substring(tokens[7].IndexOf('=') + 1);
						//final = temp.Substring(temp.IndexOf('$') - 1);
						//employees[employees.Count - 1].PayPerEmp = (int)Convert.ToDouble(final);
						continue;

					default:
						break;
				}

				employees[employees.Count - 1].Name = tokens[1] + " " + tokens[2];
				employees[employees.Count - 1].Avatar = tokens[4];
				// Create substring between '=' and '$'
				temp = tokens[5].Substring(tokens[5].IndexOf('=') + 1);
				final = temp.Substring(0, temp.IndexOf('$'));
				employees[employees.Count - 1].Payment = (int)Convert.ToDouble(final);
				// Create substring after '='
				employees[employees.Count - 1].Amount = (int)Convert.ToDouble(tokens[6].Substring(tokens[6].IndexOf('=') + 1));
			}

			return employees;
		}
	}

	public interface IEmployee: ICloneable
    {
        public string Type { get; }
		public string Name { get; set; }
        public int Payment { get; set; }
		public int PayPerEmp { get; set; }
		public int Amount { get; set; }
		public string AmountUnit { get; }
		public string Avatar { get; set; }
    }

	public class DailyEmployee : IEmployee
	{
		public string Type => "DailyEmployee";
		public string AmountUnit => "days";

		string _name = "";
		public string Name
		{
			get => _name;
			set => _name = value;
		}
		int _payment = 0;
		public int Payment
		{
			get => _payment;
			set => _payment = value;
		}
		int _amount = 0;
		public int Amount
		{
			get => _amount;
			set => _amount = value;
		}
		string _avatar = "";
		public string Avatar
		{
			get => _avatar;
			set => _avatar = value;
		}
		int _payPerEmp = 0;
		public int PayPerEmp
		{
			get => _payPerEmp;
			set => _payPerEmp = value;
		}

		public object Clone() => MemberwiseClone();
	}

	public class HourlyEmployee : IEmployee
	{
		public string Type => "HourlyEmployee";
		public string AmountUnit => "hours";

		string _name = "";
		public string Name
		{
			get => _name;
			set => _name = value;
		}
		int _payment = 0;
		public int Payment
		{
			get => _payment;
			set => _payment = value;
		}
		int _amount = 0;
		public int Amount
		{
			get => _amount;
			set => _amount = value;
		}
		string _avatar = "";
		public string Avatar
		{
			get => _avatar;
			set => _avatar = value;
		}
		int _payPerEmp = 0;
		public int PayPerEmp
		{
			get => _payPerEmp;
			set => _payPerEmp = value;
		}

		public object Clone() => MemberwiseClone();
	}

	public class ProductEmployee : IEmployee
	{
		public string Type => "ProductEmployee";
		public string AmountUnit => "products";

		string _name = "";
		public string Name
		{
			get => _name;
			set => _name = value;
		}
		int _payment = 0;
		public int Payment
		{
			get => _payment;
			set => _payment = value;
		}
		int _amount = 0;
		public int Amount
		{
			get => _amount;
			set => _amount = value;
		}
		string _avatar = "";
		public string Avatar
		{
			get => _avatar;
			set => _avatar = value;
		}
		int _payPerEmp = 0;
		public int PayPerEmp
		{
			get => _payPerEmp;
			set => _payPerEmp = value;
		}

		public object Clone() => MemberwiseClone();
	}

	public class Manager : IEmployee
	{
		public string Type => "Manager";
		public string AmountUnit => "employees";

		int _payPerEmp = 0;
		public int PayPerEmp
		{
			get => _payPerEmp;
			set => _payPerEmp = value;
		}
		string _name = "";
		public string Name
		{
			get => _name;
			set => _name = value;
		}
		int _payment = 0;
		public int Payment
		{
			get => _payment;
			set => _payment = value;
		}
		int _amount = 0;
		public int Amount
		{
			get => _amount;
			set => _amount = value;
		}
		string _avatar = "";
		public string Avatar
		{
			get => _avatar;
			set => _avatar = value;
		}

		public object Clone() => MemberwiseClone();
	}
}
