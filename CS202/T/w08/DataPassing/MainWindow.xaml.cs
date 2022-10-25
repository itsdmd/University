using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
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

namespace DataPassing
{
    public partial class MainWindow : Window, INotifyPropertyChanged
    {
        public MainWindow()
        {
            InitializeComponent();
        }

		ObservableCollection<Student> _students;
		ObservableCollection<Student> _subItems;

		private void Window_Loaded(object sender, RoutedEventArgs e)
        {
            _students = new ObservableCollection<Student>()
            {
				new Student() { ID = "001", Credits=70, Name="Nguyen Thanh Minh", Avatar="Images/avatar01.jpg"},
				new Student() { ID = "002", Credits=15, Name="Tran Duc Long", Avatar="Images/avatar02.jpg"},
				new Student() { ID = "003", Credits=22, Name="Do Huu Le", Avatar="Images/avatar03.jpg"},
				new Student() { ID = "004", Credits=88, Name="Cao Thai Tuan", Avatar="Images/avatar04.jpg"},
				new Student() { ID = "005", Credits=91, Name="Le Thanh Chien", Avatar="Images/avatar05.jpg"},
				new Student() { ID = "006", Credits=15, Name="Tran Thai An", Avatar="Images/avatar06.jpg"},
				new Student() { ID = "007", Credits=79, Name="Nguyen Linh Giang", Avatar="Images/avatar07.jpg"},
				new Student() { ID = "008", Credits=25, Name="Nguyen Thi Thu Hoa", Avatar="Images/avatar08.jpg"},
				new Student() { ID = "009", Credits=16, Name="Tran Son Vuong", Avatar="Images/avatar09.jpg"},
				new Student() { ID = "010", Credits=26, Name="Tran Quoc Tuan", Avatar="Images/avatar10.jpg"},
				new Student() { ID = "020", Credits=26, Name="Tran Quoc Tuan", Avatar="Images/avatar10.jpg"},
				new Student() { ID = "019", Credits=16, Name="Tran Son Vuong", Avatar="Images/avatar09.jpg"},
				new Student() { ID = "018", Credits=25, Name="Nguyen Thi Thu Hoa", Avatar="Images/avatar08.jpg"},
				new Student() { ID = "016", Credits=15, Name="Tran Thai An", Avatar="Images/avatar06.jpg"},
				new Student() { ID = "015", Credits=91, Name="Le Thanh Chien", Avatar="Images/avatar05.jpg"},
				new Student() { ID = "014", Credits=88, Name="Cao Thai Tuan", Avatar="Images/avatar04.jpg"},
				new Student() { ID = "017", Credits=79, Name="Nguyen Linh Giang", Avatar="Images/avatar07.jpg"},
				new Student() { ID = "013", Credits=22, Name="Do Huu Le", Avatar="Images/avatar03.jpg"},
				new Student() { ID = "012", Credits=15, Name="Tran Duc Long", Avatar="Images/avatar02.jpg"},
				new Student() { ID = "011", Credits=70, Name="Nguyen Thanh Minh", Avatar="Images/avatar01.jpg"},
				new Student() { ID = "021", Credits=70, Name="Nguyen Thanh Minh", Avatar="Images/avatar01.jpg"},
				new Student() { ID = "022", Credits=15, Name="Tran Duc Long", Avatar="Images/avatar02.jpg"},
				new Student() { ID = "023", Credits=22, Name="Do Huu Le", Avatar="Images/avatar03.jpg"},
				new Student() { ID = "024", Credits=88, Name="Cao Thai Tuan", Avatar="Images/avatar04.jpg"},
				new Student() { ID = "025", Credits=91, Name="Le Thanh Chien", Avatar="Images/avatar05.jpg"},
				new Student() { ID = "026", Credits=15, Name="Tran Thai An", Avatar="Images/avatar06.jpg"},
				new Student() { ID = "027", Credits=79, Name="Nguyen Linh Giang", Avatar="Images/avatar07.jpg"},
				new Student() { ID = "028", Credits=25, Name="Nguyen Thi Thu Hoa", Avatar="Images/avatar08.jpg"},
				new Student() { ID = "029", Credits=16, Name="Tran Son Vuong", Avatar="Images/avatar09.jpg"},
				new Student() { ID = "030", Credits=26, Name="Tran Quoc Tuan", Avatar="Images/avatar10.jpg"},
				new Student() { ID = "031", Credits=16, Name="Tran Son Vuong", Avatar="Images/avatar09.jpg"},
				new Student() { ID = "032", Credits=26, Name="Tran Quoc Tuan", Avatar="Images/avatar10.jpg"}
			};

			studentsListView.ItemsSource = _students;

			TotalItems = _students.Count();
			CurrentPage = 1;
			RowsPerPage = 10;

			DataContext = this;
			
			UpdateDisplayItems();
		}

		public int TotalItems { get; set; } = 0;
		public int TotalPages { get; set; } = 0;
		public int CurrentItemsCount { get; set; } = 0;
		public int CurrentPage { get; set; } = 0;
		public int RowsPerPage { get; set; } = 0;
		void UpdateDisplayItems()
		{
			TotalPages = (TotalItems / RowsPerPage)
						 + (TotalItems % RowsPerPage == 0 ? 0 : 1);
			
			_subItems = new ObservableCollection<Student>(
				_students
				.Skip((CurrentPage - 1) * RowsPerPage)
				.Take(RowsPerPage)
				.ToList()
			);

			CurrentItemsCount = _subItems.Count();

			studentsListView.ItemsSource = _subItems;
		}

		Student _sv = new Student();
		Student _old = new Student();
		
		private void deleteMenuItem_Click(object sender, RoutedEventArgs e)
		{

		}

		private void editMenuItem_Click(object sender, RoutedEventArgs e)
		{
			int index = studentsListView.SelectedIndex;
			_sv = _students[index];
			_old = (Student)_sv.Clone();

			var screen = new DestinationWindow(_sv);
			screen.CreditChanged += Screen_CreditChanged;
			screen.AvatarChanged += Screen_AvatarChanged;

			if (screen.ShowDialog() == true)
			{
				_students[index] = screen.ReturnData;
			}
			else
			{
				_students[index] = _old;
			}
		}


		private void Screen_CreditChanged(int newValue)
		{
			int index = studentsListView.SelectedIndex;
			_sv = _students[index];
			_sv.Credits = newValue;
		}

		private void Screen_AvatarChanged(string newImg)
		{
			int index = studentsListView.SelectedIndex;
			_sv = _students[index];
			_sv.Avatar = newImg;
		}

		private void prevButton_Click(object sender, RoutedEventArgs e)
		{
			if (CurrentPage > 1)
			{
				CurrentPage--;
				UpdateDisplayItems();
			}
		}

		private void nextButton_Click(object sender, RoutedEventArgs e)
		{
			if (CurrentPage < TotalPages)
			{
				CurrentPage++;
				UpdateDisplayItems();
			}
		}
	}
}