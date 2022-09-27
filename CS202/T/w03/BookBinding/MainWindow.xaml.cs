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

namespace BookBinding
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

		class Book
		{
			public string Name { get; set; }
			public string Author { get; set; }
			public int PubYear { get; set; }
			public string CoverPath { get; set; }
		}


		static Book _book = new Book()
		{
			Name = "Problems in General Physics",
			Author = "I. F. Irodov",
			PubYear = 2011,
			CoverPath = "res/cover.jpg"
		};


		private void Window_Loaded(object sender, RoutedEventArgs e)
		{
			this.DataContext = _book;
		}
	}
}
