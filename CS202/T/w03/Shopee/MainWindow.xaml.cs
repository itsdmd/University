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

namespace Shopee
{
	/// <summary>
	/// Interaction logic for Shopee.xaml
	/// </summary>
	public partial class Shopee : Window
	{
		public void SetFlashSale()
		{
			fst1.Text = "109.000";
			fst2.Text = "150.000";
			fst3.Text = "115.000";
			fst4.Text = "169.000";
			fst5.Text = "217.000";
			fst6.Text = "91.000";
		}

		public Shopee()
		{
			InitializeComponent();
			SetFlashSale();
		}
	}
}
