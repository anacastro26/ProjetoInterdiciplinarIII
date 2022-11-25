$(document).ready(function () {
  $.ajax({
    url: "http://192.168.1.101",
    success: function (data) {
      console.log(data);
      const vagas = data.variables;
      const keys = Object.keys(vagas);
      const arr = keys.map((k) => ({ k: vagas[k] }));

      console.log(arr);

      document.getElementById("Vagas1").innerHTML = arr[0].k;
      document.getElementById("Vagas2").innerHTML = arr[1].k;
      document.getElementById("Vagas3").innerHTML = arr[2].k;
      document.getElementById("Vagas4").innerHTML = arr[3].k;

      if (arr[0].k > 20) {
        $("#dVaga0").css("background-color", "#02ca63");
      } else {
        $("#dVaga0").css("background-color", "#ff0000");
      }
      if (arr[1].k > 20) {
        $("#dVaga1").css("background-color", "#02ca63");
      } else {
        $("#dVaga1").css("background-color", "#ff0000");
      }
      if (arr[2].k > 20) {
        $("#dVaga2").css("background-color", "#02ca63");
      } else {
        $("#dVaga2").css("background-color", "#ff0000");
      }
      if (arr[3].k > 20) {
        $("#dVaga3").css("background-color", "#02ca63");
      } else {
        $("#dVaga3").css("background-color", "#ff0000");
      }
    },
  });
});

//Set interval
