using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
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

namespace CompanySalary
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

		private void Window_Loaded(object sender, RoutedEventArgs e)
		{
			//string exeFolder = AppDomain.CurrentDomain.BaseDirectory;
			//string imagesFolder = $"{exeFolder}Images";

			//DirectoryInfo info = new DirectoryInfo(imagesFolder);
			//var files = info.GetFiles("*.jpg");

			Factory f = new Factory();
			List<IEmployee> employees = f.Generate("November2022.txt");

			var previews = from employee in employees
						   select new
						   {
							   Avatar = $"Images/{employee.Avatar}",
								Type = employee.Type,
								Name = employee.Name
							};
			previewListView.ItemsSource = previews;
		}

  //      Employee _old = new Employee();
        private void sendButton_Click(object sender, RoutedEventArgs e)
        {
			//	_old = (Employee)_em.Clone();

			//	var screen = new DestinationWindow(_em);
			//	screen.AvatarChanged += Screen_AvatarChanged;

			//	if (screen.ShowDialog() == true)
			//          {
			//              _em = screen.ReturnData;
			//              DataContext = _em;
			//          } else
			//          {
			//              _em = _old;
			//		DataContext = _em;
			//	}
		}
	}
}
