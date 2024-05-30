//13. And press ENTER

$(document).ready(function() {
    function fetchHello() {
        const languageCode = $('#language_code').val();
        const apiUrl = `https://www.fourtonfish.com/hellosalut/hello/?lang=${languageCode}`;

        $.get(apiUrl, function(data) {
            $('#hello').text(data.hello);
        });
    }

    $('#btn_translate').click(function() {
        fetchHello();
    });

    $('#language_code').keypress(function(event) {
        if (event.which === 13) { // 13 is the Enter key
            fetchHello();
        }
    });
});
