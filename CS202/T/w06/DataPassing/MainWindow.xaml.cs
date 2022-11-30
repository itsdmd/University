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


        Student _sv = new Student()
        {
            ID = "001",
            Name = "Nguyen Mai Huong",
            Credits = 80,
            Avatar = "Images/avatar01.jpg"
        };

        private void Window_Loaded(object sender, RoutedEventArgs e)
        {
            DataContext = _sv;
        }

        Student _old = new Student();
        private void sendButton_Click(object sender, RoutedEventArgs e)
        {
			_old = (Student)_sv.Clone();

			var screen = new DestinationWindow(_sv);
            screen.CreditChanged += Screen_CreditChanged;
			screen.AvatarChanged += Screen_AvatarChanged;

			if (screen.ShowDialog() == true)
            {
                _sv = screen.ReturnData;
                DataContext = _sv;
            } else
            {
                _sv = _old;
				DataContext = _sv;
			}
        }


        
        private void Screen_CreditChanged(int newValue)
        {
            _sv.Credits = newValue;
        }

		private void Screen_AvatarChanged(string newImg)
        {
			_sv.Avatar = newImg;
		}
    }
}
