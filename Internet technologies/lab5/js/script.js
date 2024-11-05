
$(document).ready(function () {

    /*Ajax*/

    $('.ajax__button').click(function (file) {
        $.ajax({
            url: "json/gallery.json",
            dataType: "json",
            success: function (data) {
                file = data;
                progress();
            }
        });

        function loadImages() {
            for (var i = 0; i < file.images.length; i++) {
                $('.ajax__row').append('<img class="ajax__image" src="img/ajax/' + file.images[i].file + '">');
            }
        }

        function progress() {
            let progressValue = 0;
            $('.ajax__row').empty();
            $('.ajax__progress-bar ').empty();
            $('.ajax__button').css({'display' : 'none'});

            $('.ajax__progress-bar').append('<div class="ajax__progress"></div>');

            let interval = setInterval(function () {
                progressValue++;
                $(".ajax__progress").progressbar({ value: progressValue });
                if (progressValue == 100) {
                    clearInterval(interval);
                    loadImages();
                    $('.ajax__progress-bar').empty();
                    $('.ajax__button').css({'display' : 'block'});
                }
            }, 5);
        }
    });

    /*Слайдер*/
    let position = 0;
    let currentSlide = 1;
    const sliderBlock = $('.slider__block');
    const sliderTrack = $('.slider__track')
    const sliderItem = $('.slider__item');
    const itemWidth = sliderBlock.width();
    const itemsCount = sliderItem.length;

    function setPosition() {
        $(sliderTrack).css({
            transform: `translateX(${position}px)`
        });
    }

    $('.main__prev-button').click(function (e) {
        if (currentSlide > 1) {
            position += itemWidth;
            currentSlide--;
            setPosition();
        }
    });

    $('.main__next-button').click(function (e) {
        if (currentSlide < itemsCount) {
            position -= itemWidth;
            setPosition();
            currentSlide++;
        }
    });

    /*Меню Аккордеон*/
    $('.accordion__header').click(function (e) {
        $(this).toggleClass('active').next().slideToggle(300);
    });

    /*Tab меню*/

    $( function() {
        $( ".tabs__block" ).tabs();
      } );

    //Datepicker
    $(function () {
        $(".date__datepicker").datepicker();
    });
});


