using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DataPassing
{
	public class Student : INotifyPropertyChanged
	{
		public string ID { get; set; }
		public string Name { get; set; }
		public int Credits { get; set; }
		public string AvatarPath { get; set; }

		public event PropertyChangedEventHandler? PropertyChanged;

		// Create a copy of the object
		public object Clone() 
		{
			return MemberwiseClone();
		}
	}
}
