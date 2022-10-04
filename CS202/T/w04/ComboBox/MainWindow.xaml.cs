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

namespace ComboBox
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
			public int Credits { get; set; }
			public string AvatarPath { get; set; }
		}


		static Student _sv1 = new Student()
		{
			ID = "001",
			Name = "John",
			Credits = 75,
			AvatarPath = "res/cup.png"
		};

		static Student _sv2 = new Student()
		{
			ID = "002",
			Name = "Jim",
			Credits = 120,
			AvatarPath = "res/cucumber.png"
		};

		List<Student> _list;

		private void Window_Loaded(object sender, RoutedEventArgs e)
		{
			_list = new List<Student>();
			_list.Add(_sv1);
			_list.Add(_sv2);

			studentComboBox.ItemsSource = _list;
		}
	}
}
