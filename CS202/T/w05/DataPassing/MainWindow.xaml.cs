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
	public partial class MainWindow : Window
	{
		public MainWindow()
		{
			InitializeComponent();
		}

		static Student _sv = new Student()
		{
			ID = "001",
			Name = "John",
			Credits = 75,
			AvatarPath = "res/1.jpg"
		};

		private void Window_Loaded(object sender, RoutedEventArgs e)
		{
			DataContext = _sv;
		}

		private void Screen_Handler(int newVal)
		{
			_sv.Credits = newVal;
		}

		int _oldSliderVal = 0;
		private void sendButton_Click(object sender, RoutedEventArgs e)
		{
			var screen = new Destination(_sv);
			_oldSliderVal = _sv.Credits;
			screen.Handler += Screen_Handler;
			
			if (screen.ShowDialog() == true)
			{
				_sv = screen.ReturnData;
				DataContext = _sv;
			} else
			{
				_sv.Credits = _oldSliderVal;
			}
		}
	}
}
