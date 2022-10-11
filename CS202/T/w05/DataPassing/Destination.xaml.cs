using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Shapes;

namespace DataPassing
{
	public partial class Destination : Window
	{
		// Hold modified data from the textbox
		public Student ReturnData { get; set; }

		public Destination(Student _sv)
		{
			InitializeComponent();

			ReturnData = (Student)_sv.Clone();
		}

		private void Window_Loaded(object sender, RoutedEventArgs e)
		{
			DataContext = ReturnData;
		}

		private void okButton_Click(object sender, RoutedEventArgs e)
		{
			// Close the window and return the modified data
			DialogResult = true;
		}
	}
}
