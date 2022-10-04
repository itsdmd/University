using System;
using System.Collections.Generic;
using System.ComponentModel;
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
			public string Program { get; set; }
			public string AvatarPath { get; set; }
		}


		static Student _sv1 = new Student()
		{
			ID = "001",
			Name = "John",
			Program = "Standard",
			AvatarPath = "res/1.jpg"
		};

		static Student _sv2 = new Student()
		{
			ID = "002",
			Name = "Jim",
			Program = "ITEC",
			AvatarPath = "res/2.jpg"
		};

		static Student _sv3 = new Student()
		{
			ID = "003",
			Name = "Joe",
			Program = "ITEC",
			AvatarPath = "res/3.jpg"
		};

		static Student _sv4 = new Student()
		{
			ID = "004",
			Name = "Jules",
			Program = "Standard",
			AvatarPath = "res/4.jpg"
		};

		static Student _sv5 = new Student()
		{
			ID = "005",
			Name = "Jake",
			Program = "Standard",
			AvatarPath = "res/5.jpg"
		};

		BindingList<Student> _list;

		private void Window_Loaded(object sender, RoutedEventArgs e)
		{
			_list = new BindingList<Student>();
			_list.Add(_sv1);
			_list.Add(_sv2);

			studentComboBox.ItemsSource = _list;
		}

		private void addStudent_Click(object sender, RoutedEventArgs e)
		{
			_list.Add(_sv3);
			_list.Add(_sv4);
			_list.Add(_sv5);
		}

		private void delStudent_Click(object sender, RoutedEventArgs e)
		{
			_list.RemoveAt(studentComboBox.SelectedIndex);
		}
	}
}
