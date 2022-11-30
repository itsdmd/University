using System;
using System.Collections.Generic;
using System.Globalization;
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
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace DataBinding
{
	/// <summary>
	/// Interaction logic for MainWindow.xaml
	/// </summary>
	public partial class MainWindow : Window
	{
		public MainWindow()
		{
			InitializeComponent();
		}

		class Student
		{
			public string ID { get; set; }
			public string Name { get; set; }
			public int YOB { get; set; }
			public int Credits { get; set; }
			public int TotalCred { get; set; }
			public string AvatarPath { get; set; }
		}


		static Student _sv = new Student()
		{
			ID = "001",
			Name = "Test",
			YOB = 2000,
			Credits = 99,
			TotalCred = 140,
			AvatarPath = "Images/chocolate.png"
		};

		private void Window_Loaded(object sender, RoutedEventArgs e)
		{
			this.DataContext = _sv;
		}

		private void Button_Click(object sender, RoutedEventArgs e)
		{
			int age = DateTime.Now.Year - _sv.YOB;
			MessageBox.Show($"Ban {age} tuoi");
		}
	}
}
