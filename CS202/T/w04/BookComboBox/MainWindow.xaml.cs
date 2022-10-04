using System;
using System.Collections.Generic;
using System.ComponentModel;
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

namespace BookComboBox
{
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


		static Book _b1 = new Book()
		{
			Name = "Problems in General Physics",
			Author = "I. F. Irodov",
			PubYear = 2011,
			CoverPath = "res/1.jpg"
		};

		static Book _b2 = new Book()
		{
			Name = "Higher Engineering Mathematics",
			Author = "John Bird",
			PubYear = 2010,
			CoverPath = "res/2.jpg"
		};

		static Book _b3 = new Book()
		{
			Name = "Essentials of Anatomy and Physiology",
			Author = "Valerie C. Scanlon",
			PubYear = 2007,
			CoverPath = "res/3.jpg"
		};

		static Book _b4 = new Book()
		{
			Name = "Influence: The Psychology of Persuasion",
			Author = "Robert B. Cialdini",
			PubYear = 2009,
			CoverPath = "res/4.jpg"
		};

		static Book _b5 = new Book()
		{
			Name = "International Law and International Relations",
			Author = "Beth A. Simmons",
			PubYear = 2007,
			CoverPath = "res/5.jpg"
		};

		static Book _b6 = new Book()
		{
			Name = "Digital Logic And Computer Design",
			Author = "M. Morris Mano",
			PubYear = 2006,
			CoverPath = "res/6.jpg"
		};

		static Book _b7 = new Book()
		{
			Name = "Atlas of Human Anatomy",
			Author = "Frank H. Netter",
			PubYear = 2018,
			CoverPath = "res/7.jpg"
		};

		static Book _b8 = new Book()
		{
			Name = "International Political Economy",
			Author = "Jeffry A. Frieden",
			PubYear = 2003,
			CoverPath = "res/8.jpg"
		};

		static Book _b9 = new Book()
		{
			Name = "Essentials of Ecology",
			Author = "G. Tyler Miller",
			PubYear = 2010,
			CoverPath = "res/9.jpg"
		};

		static Book _b10 = new Book()
		{
			Name = "The Decisive Battles of World History",
			Author = "Gregory S. Aldrete",
			PubYear = 2014,
			CoverPath = "res/10.jpg"
		};

		BindingList<Book> _list;

		private void Window_Loaded(object sender, RoutedEventArgs e)
		{
			_list = new BindingList<Book>();
			_list.Add(_b1);
			_list.Add(_b2);
			_list.Add(_b3);
			_list.Add(_b4);
			_list.Add(_b5);
			_list.Add(_b6);
			_list.Add(_b7);
			_list.Add(_b8);
			_list.Add(_b9);

			bookComboBox.ItemsSource = _list;
		}

		private void addBook_Click(object sender, RoutedEventArgs e)
		{
			_list.Add(_b10);
		}

		private void delBook_Click(object sender, RoutedEventArgs e)
		{
			if (bookComboBox.HasItems && bookComboBox.SelectedIndex >= 0)
			{
				_list.RemoveAt(bookComboBox.SelectedIndex);
			}
		}

		private void updBook_Click(object sender, RoutedEventArgs e)
		{
			_list[bookComboBox.SelectedIndex] = _b7;
		}
	}
}
