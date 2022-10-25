﻿using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Data;

namespace DataPassing
{
    public class RelativeToAbsoluteConveter : IValueConverter
    {
        public object Convert(object value, Type targetType, object parameter, CultureInfo culture)
        {
            var folder = AppDomain.CurrentDomain.BaseDirectory;

            string relativePath = (string)value;
			
			if (relativePath.Contains(':'))
				return relativePath;

			string absolutePath = $"{folder}{relativePath}";

            return absolutePath;
        }

        public object ConvertBack(object value, Type targetType, object parameter, CultureInfo culture)
        {
            throw new NotImplementedException();
        }
    }
}
