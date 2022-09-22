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
		static Tuple<double, double, double, double, double, double> JARS(double income)
		{
			double[] distro = new double[6] { (0.55f * income),	// Neccessities
											(0.1f * income),	// Long-term
											(0.1f * income),    // Play
											(0.1f * income),    // Education
											(0.1f * income),    // Financial
											(0.05f * income) }; // Give

			Tuple<double, double, double, double, double, double> jars = new(distro[0], distro[1], distro[2],
																		distro[3], distro[4], distro[5]);

			return jars;
		}

		static string Converter(double inp)
		{
			CultureInfo cul = CultureInfo.GetCultureInfo("vi-VN");
			return inp.ToString("#,###", cul.NumberFormat);
		}

		public void DisplayJars(string income)
		{
			double converted = double.Parse(income);
			Tuple<double, double, double, double, double, double> jars = JARS(converted);

			nec.Text = Converter(jars.Item1);
			ltrm.Text = Converter(jars.Item2);
			play.Text = Converter(jars.Item3);
			edu.Text = Converter(jars.Item4);
			fin.Text = Converter(jars.Item5);
			give.Text = Converter(jars.Item6);
		}

		private void Button_Click(object sender, RoutedEventArgs e)
		{
			DisplayJars(incomeInput.Text);
		}

		public MainWindow()
		{
			InitializeComponent();
		}
	}
}
