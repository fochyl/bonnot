#include <sil/sil.hpp>
#include "random.hpp"
#include <math.h>
#include <stdlib.h>
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

void vert(sil::Image image)
{
    for (glm::vec3 &color : image.pixels())
    {
        color.r = 0.f;
        color.b = 0.f;
    }
    // TODO: modifier l'image
    image.save("output/pouet_vert.png");
}

void canaux(sil::Image image)
{
    for (glm::vec3 &color : image.pixels())
    {
        std::swap(color.r, color.b);
    }
    // TODO: modifier l'image
    image.save("output/pouet_canaux.png");
}

void gris(sil::Image image)
{
    for (glm::vec3 &color : image.pixels())
    {
        float moyenne = (color.r + color.g + color.b) / 3;
        color.r = moyenne;
        color.g = moyenne;
        color.b = moyenne;
    }
    // TODO: modifier l'image
    image.save("output/pouet_gris.png");
}

void negatif(sil::Image image)
{
    for (glm::vec3 &color : image.pixels())
    {
        color.r = (1 - color.r);
        color.g = (1 - color.g);
        color.b = (1 - color.b);
    }
    // TODO: modifier l'image
    image.save("output/pouet_negatif.png");
}

void degrade(sil::Image vide)
{
    for (int x{0}; x < vide.width(); x++)
    {
        float valeur = static_cast<float>(x) / vide.width();
        for (int y{0}; y < vide.height(); y++)
        {
            vide.pixel(x, y).r = valeur;
            vide.pixel(x, y).g = valeur;
            vide.pixel(x, y).b = valeur;
        }
    }
    // TODO: modifier l'image
    vide.save("output/vide_degrade.png");
}

void miroir(sil::Image image)
{
    for (int x{0}; x < image.width() / 2; x++)
    {
        for (int y{0}; y < image.height(); y++)
        {
            std::swap(image.pixel(x, y), image.pixel(image.width() - 1 - x, y));
        }
    }
    // TODO: modifier l'image
    image.save("output/pouet_miroir.png");
}

void bruit(sil::Image image)
{
    for (glm::vec3 &color : image.pixels())
    {
        int random{random_int(0, 9)};

        if (random == 0)
        {
            color.r = random_float(0, 1);
            color.g = random_float(0, 1);
            color.b = random_float(0, 1);
        }
    }
    // TODO: modifier l'image
    image.save("output/pouet_bruit.png");
}

void rotation(sil::Image image)
{
    sil::Image fond{image.height(), image.width()};
    for (int x{0}; x < image.width(); x++)
    {
        for (int y{0}; y < image.height(); y++)
        {
            fond.pixel(y, x) = image.pixel(x, image.height() - y - 1);
        }
    }
    // TODO: modifier l'image
    fond.save("output/pouet_rotation.png");
}

void split(sil::Image image)
{
    sil::Image image2(image);
    for (int x{0}; x < image.width(); x++)
    {
        for (int y{0}; y < image.height(); y++)
        {
            if (x + 15 > image.width() - 1)
            {
                image2.pixel(x, y).r = image.pixel(image.width() - 1, y).r;
                // image2.pixel(x, y).g = image.pixel(image.width() -1, y).g ;
                image2.pixel(x, y).b = image.pixel(image.width() - 1, y).b;
            }
            else if (x - 15 < 0)
            {
                image2.pixel(x, y).r = image.pixel(0, y).r;
                // image2.pixel(x, y).g = image.pixel(0, y).g ;
                image2.pixel(x, y).b = image.pixel(0, y).b;
            }
            else
            {
                image2.pixel(x, y).r = image.pixel(x + 15, y).r;
                // image2.pixel(x, y).g = image.pixel(x, y).g ;
                image2.pixel(x, y).b = image.pixel(x - 15, y).b;
            }
        }
    }
    // TODO: modifier l'image
    image2.save("output/pouet_split.png");
}

void assombrissement(sil::Image photo)
{
    for (glm::vec3 &color : photo.pixels())
    {
        color.r = pow(color.r, 2.5);
        color.g = pow(color.g, 2.5);
        color.b = pow(color.b, 2.5);
    }
    // TODO: modifier l'image
    photo.save("output/photo_assombrie.png");
}

void eclaircissement(sil::Image photo)
{
    for (glm::vec3 &color : photo.pixels())
    {
        color.r = pow(color.r, 0.25);
        color.g = pow(color.g, 0.25);
        color.b = pow(color.b, 0.25);
    }
    // TODO: modifier l'image
    photo.save("output/photo_eclaircie.png");
}

void disque(sil::Image fond)
{
    for (int x{0}; x < fond.width(); x++)
    {
        for (int y{0}; y < fond.height(); y++)
        {
            if (pow(x - fond.width() / 2, 2) + pow(y - fond.height() / 2, 2) < 10000)
            {
                fond.pixel(x, y).r = 255;
                fond.pixel(x, y).g = 255;
                fond.pixel(x, y).b = 255;
            };
        }
    }
    // TODO: modifier l'image
    fond.save("output/fond_disque.png");
}

void cercle(sil::Image fond, int thickness)
{
    for (int x{0}; x < fond.width(); x++)
    {
        for (int y{0}; y < fond.height(); y++)
        {
            if (pow(x - fond.width() / 2, 2) + pow(y - fond.height() / 2, 2) > 10000 - thickness && pow(x - fond.width() / 2, 2) + pow(y - fond.height() / 2, 2) < 10000 + thickness)
            {
                fond.pixel(x, y).r = 255;
                fond.pixel(x, y).g = 255;
                fond.pixel(x, y).b = 255;
            };
        }
    }
    // TODO: modifier l'image
    fond.save("output/fond_cercle.png");
}

void rosace(sil::Image fond, int thickness)
{
    for (int x{0}; x < fond.width(); x++)
    {
        for (int y{0}; y < fond.height(); y++)
        {
            if (pow(x - fond.width() / 2, 2) + pow(y - fond.height() / 2, 2) > 10000 - thickness && pow(x - fond.width() / 2, 2) + pow(y - fond.height() / 2, 2) < 10000 + thickness)
            {
                fond.pixel(x, y).r = 255;
                fond.pixel(x, y).g = 255;
                fond.pixel(x, y).b = 255;
            };

            if (pow(x - fond.width() / 4, 2) + pow(y - fond.height() / 4, 2) > 10000 - thickness && pow(x - fond.width() / 4, 2) + pow(y - fond.height() / 4, 2) < 10000 + thickness)
            {
                fond.pixel(x, y).r = 255;
                fond.pixel(x, y).g = 255;
                fond.pixel(x, y).b = 255;
            };
        }
    }
    // TODO: modifier l'image
    fond.save("output/fond_rosace.png");
}

int main()
{
    sil::Image image{"images/logo.png"};
    sil::Image vide{150 /*width*/, 200 /*height*/};
    sil::Image photo{"images/photo.jpg"};
    sil::Image fond{500 /*width*/, 500 /*height*/};
    /*vert(image);
    canaux(image);
    gris(image) ;
    negatif(image) ;
    degrade(vide) ;
    miroir(image) ;
    bruit(image) ;
    rotation(image) ;
    split(image) ;
    assombrissement(photo) ;
    eclaircissement(photo) ;*/
    disque(fond);
    cercle(fond, 200);
    rosace(fond, 200) ;
}