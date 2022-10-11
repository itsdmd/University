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
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace DataPassing
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

		static Student _sv1 = new Student()
		{
			ID = "001",
			Name = "John",
			Credits = 75,
			AvatarPath = "res/1.jpg"
		};

		private void Window_Loaded(object sender, RoutedEventArgs e)
		{
			DataContext = _sv1;
		}

		private void okButton_Click(object sender, RoutedEventArgs e)
		{
			var screen = new Destination(_sv1);
			
			if (screen.ShowDialog() == true)
			{
				// Update the data context for the main window with the modified data returned from the destination window
				DataContext = screen.ReturnData;
			} else
			{
				Title = "Nothing returned";
			}
		}
	}
}
