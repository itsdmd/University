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
using System.Windows.Shapes;

namespace CompanySalary
{
    /// <summary>
    /// Interaction logic for DestinationWindow.xaml
    /// </summary>
    public partial class DestinationWindow : Window
    {
        // Public property
        //public Employee ReturnData { get; set; }

        public DestinationWindow(IEmployee _sv)
        {
            InitializeComponent();

            //ReturnData = (Employee)_sv.Clone();
        }

        private void Window_Loaded(object sender, RoutedEventArgs e)
        {
            //string exeFolder = AppDomain.CurrentDomain.BaseDirectory;
            //string imagesFolder = $"{exeFolder}Images";

            //DirectoryInfo info = new DirectoryInfo(imagesFolder);
            //var files = info.GetFiles("*.jpg");

            //Debug.WriteLine($"Found {files.Length} images");
            //foreach(var file in files )
            //{
            //    Debug.WriteLine(file.Name);
            //}
			
            //var previews = from f in files
            //               select new
            //               {
            //                   Avatar = $"Images/{f.Name}"
            //               };
            //previewListView.ItemsSource = previews;

            //DataContext = ReturnData;
        }

        private void okButton_Click(object sender, RoutedEventArgs e)
        {
            //          DialogResult = true;
        }

    //public delegate void AvatarChangedHandler(string newImage);
    //public event AvatarChangedHandler AvatarChanged;
          private void previewListView_SelectionChanged(object sender, SelectionChangedEventArgs e)
    {
        //          dynamic info = previewListView.SelectedItem;

        //          ReturnData.Avatar = info.Avatar;
        //          AvatarChanged?.Invoke(info.Avatar);
    }
}
}
