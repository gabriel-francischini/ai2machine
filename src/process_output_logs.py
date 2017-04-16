import sys
import codecs

del sys.argv[0]

i = 0

#for filename in sys.argv:
for i in range(430):
	filename = "log" + str(i) + ".txt"
	file = open(filename, 'r', encoding='latin-1', errors='ignore')

	savefile = filename
	savefile = savefile.split('.')[0]
	savefile += ".html"

	savefile = open(savefile, 'w')

	randcount = savefile.write("""<html>
  <head>
    <!--Load the AJAX API-->
    <script type="text/javascript" src="https://www.gstatic.com/charts/loader.js"></script>
    <script type="text/javascript">

      // Load the Visualization API and the corechart package.
      google.charts.load('current', {'packages':['corechart']});

      // Set a callback to run when the Google Visualization API is loaded.
      google.charts.setOnLoadCallback(drawChart);

      // Callback that creates and populates a data table,
      // instantiates the pie chart, passes in the data and
      // draws it.
      function drawChart() {

        // Create the data table.
        var data = google.visualization.arrayToDataTable([
        ['Generation', 'Best Reader', 'Median Reader', 'Worst Reader', 'Best Writer', 'Median Writer', 'Worst Writer']""")

	error = False
	generation = -1
	best_reader = -1
	best_writer = -1
	worst_reader = -1
	worst_writer = -1
	median_writer = -1
	median_reader = -1
	mutation_chance = -1
	crossover_rate = -1
	beginning = "[]"
	end = "[]"


	for line in file:

		if(error == True):
			print(line)

		if(line.count("Program received signal ") > 0):
			error = True
			print("\n\n*-*-*-*-*-**-*-*-*-*-*-*-*-*\n\n")
			print(line)

		if(line.count("Started generation") > 0):
			strGeneration = line
			strGeneration = line.rsplit(' ', 1)[1]

			if(generation > -1):
				stringToPrint = ",\n"
				stringToPrint += " "*10
				stringToPrint += "[" + str(generation) + ","
				stringToPrint += "  "
				stringToPrint += str(best_reader) + ","
				stringToPrint += "  "
				stringToPrint += str(median_reader) + ","
				stringToPrint += "  "
				stringToPrint += str(worst_reader) + ","
				stringToPrint += "  "
				stringToPrint += str(best_writer) + ","
				stringToPrint += "  "
				stringToPrint += str(median_writer) + ","
				stringToPrint += "  "
				stringToPrint += str(worst_writer)
				stringToPrint += "]"

				savefile.write(stringToPrint)

			end = line.split(']', 1)[0]


			generation = int(strGeneration.strip())

		if(line.count("Score of the best reader") > 0):
			str_best_reader = line
			str_best_reader = line.rsplit(':', 1)[1]
			best_reader = int(str_best_reader.strip())


		if(line.count("The median score for readers is") > 0):
			str_median_reader = line
			str_median_reader = line.rsplit(':', 1)[1]
			median_reader = int(str_median_reader.strip())
		

		if(line.count("Score of the worst reader") > 0):
			str_worst_reader = line
			str_worst_reader = line.rsplit(':', 1)[1]
			worst_reader = int(str_worst_reader.strip())

		if(line.count("Score of the best writer") > 0):
			str_best_writer = line
			str_best_writer = line.rsplit(':', 1)[1]
			best_writer = int(str_best_writer.strip())

		if(line.count("The median score for writers is") > 0):
			str_median_writer = line
			str_median_writer = line.rsplit(':', 1)[1]
			median_writer = int(str_median_writer.strip())
		

		if(line.count("Score of the worst writer") > 0):
			str_worst_writer = line
			str_worst_writer = line.rsplit(':', 1)[1]
			worst_writer = int(str_worst_writer.strip())


		if(line.count("Crossover ") > 0):
			strGeneration = line
			strGeneration = line.split('at ', 1)[1]
			#print(strGeneration)
			crossover_rate = int(strGeneration.split(' ', 1)[0].strip())
			mutation_chance = int (strGeneration.split('at ', 1)[1].strip())
		
		if(line.count("Started generation 0") > 0):
			strGeneration = line
			beginning = line.split(']', 1)[0]


	randcount = savefile.write("""
		]);


        // Set chart options
        var options = {
        			   'title':'""" + filename + " - CR: " + str(crossover_rate) + ", CM: " + str(mutation_chance) +  " -- (" + beginning + "]:" + end + "])" +  """',
                       'width':1024,
                       'height':768,
                       hAxis: {
        					title: 'Generation'
       					 },
       				   vAxis: {
         			   		title: 'Score'
        			   },
        			   trendlines: {
         					0: {type: 'linear', color: '#FF0000', opacity: .3},
          					1: {type: 'linear', color: '#00FF00', opacity: .3},
          					2: {type: 'linear', color: '#0000FF', opacity: .3},
          					3: {type: 'linear', color: '#FF00FF', opacity: .3},
          					4: {type: 'linear', color: '#00FFFF', opacity: .3},
          					5: {type: 'linear', color: '#FFFF00', opacity: .3}
        				}

                       };

        // Instantiate and draw our chart, passing in some options.
        var chart = new google.visualization.LineChart(document.getElementById('chart_div'));
        chart.draw(data, options);
      }
    </script>
  </head>

  <body>
    <!--Div that will hold the pie chart-->
    <div id="chart_div"></div>
  </body>
</html>
		""")

	savefile.close()
	savefile = " "