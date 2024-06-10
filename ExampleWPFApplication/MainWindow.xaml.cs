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

namespace ExampleWPFApplication
{
   /// <summary>
   /// Interaction logic for MainWindow.xaml
   /// </summary>
   public partial class MainWindow : Window, InteropDependencies.IManagedCallCount
   {
      public MainWindow()
      {
         _gate = new GateInterop.GateClass( this );
         InitializeComponent();
      }

      GateInterop.GateClass _gate;

      private void btnTest_Click( object sender, RoutedEventArgs e )
      {
         editTest.Text = _gate.GetFromNative();
      }

      private int _callcount = 0;
      public int GetAndIncrementCallCount() => ++_callcount;
   }
}
