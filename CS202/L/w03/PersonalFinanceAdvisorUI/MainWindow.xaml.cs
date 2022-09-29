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

namespace PersonalFinanceAdvisorUI
{
	/// <summary>
	/// Interaction logic for MainWindow.xaml
	/// </summary>


	public partial class MainWindow : Window
	{
		class Jars
		{
			public string Necessities { get; set; }
			public string LongTerm { get; set; }
			public string Play { get; set; }
			public string Education { get; set; }
			public string Financial { get; set; }
			public string Give { get; set; }
		}

		static double _income = 0.0;
		static Jars _jars = new Jars();

		static string Converter(double inp)
		{
			CultureInfo cul = CultureInfo.GetCultureInfo("vi-VN");
			return inp.ToString("N", cul.NumberFormat);
		}

		private void Button_Click(object sender, RoutedEventArgs e)
		{
			_income = double.Parse(incomeInput.Text);
			_jars = new Jars()
			{
				Necessities = Converter(0.55 * _income),
				LongTerm = Converter(0.1 * _income),
				Play = Converter(0.1 * _income),
				Education = Converter(0.1 * _income),
				Financial = Converter(0.1 * _income),
				Give = Converter(0.05 * _income)
			};

			this.DataContext = _jars;
		}

		public MainWindow()
		{
			InitializeComponent();
		}
	}
}
